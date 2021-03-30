#include <pthread.h>
#include "caltrain.h"

void
station_init(struct station *station)
{
    station->seats = 0;
    station->waiting_passengers = 0;    //no passengers on station yet
    station->leaving_passengers = 0;    //no passengers on board yet

	pthread_mutex_init(&(station->mutex), NULL);
	pthread_cond_init(&(station->arrival), NULL);
	pthread_cond_init(&(station->leaving), NULL);
}

void
station_load_train(struct station *station, int count)
{
    pthread_mutex_lock(&(station ->mutex));
    if(count == 0 || station->waiting_passengers == 0){  //passenger may come at the same moment train arrives
        pthread_mutex_unlock(&(station->mutex));        //Race_Condition, must use mutex here
        return;
    }
    station->seats = count;
    pthread_cond_broadcast(&(station->arrival));
    pthread_cond_wait(&(station->leaving), &(station->mutex));
    pthread_mutex_unlock(&(station->mutex));
}

void
station_wait_for_train(struct station *station)
{
    pthread_mutex_lock(&(station->mutex));
    station->waiting_passengers++;          //one passenger reaches station at a time
    while(station->seats == 0)
        pthread_cond_wait(&(station->arrival), &(station->mutex));
    station->seats--;
    station->waiting_passengers--;
    station->leaving_passengers++;
    pthread_mutex_unlock(&(station->mutex));
}

void
station_on_board(struct station *station)
{
    pthread_mutex_lock(&(station->mutex));
    station->leaving_passengers--;
	if(station->leaving_passengers == 0 && (station->seats == 0 || station->waiting_passengers == 0))
        pthread_cond_signal(&(station->leaving));
    pthread_mutex_unlock(&(station->mutex));
}

