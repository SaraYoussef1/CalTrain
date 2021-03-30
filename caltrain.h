#include <pthread.h>

struct station {

    pthread_mutex_t mutex;         //control critical section
    pthread_cond_t arrival;        //signal when train arrives station
    pthread_cond_t leaving;        //signal when train is ready to leave

    int seats;                      //available seats
    int waiting_passengers;         //passengers on station
    int leaving_passengers;         //passengers on board
};

void station_init(struct station *station);

void station_load_train(struct station *station, int count);

void station_wait_for_train(struct station *station);

void station_on_board(struct station *station);
