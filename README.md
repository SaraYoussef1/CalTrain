# CalTrain
It's a train station control system that automats not just its trains but also its passengers.  
From now on, passengers will be robots.  
Each robot and each train is controlled by a thread.  

### The system works as the following:

• When a train arrives in the station and has opened its doors, it invokes the function:  
**station load train(struct station * station, int count)**  
  where "count" indicates how many seats are available on the train after it is satisfactorily loaded.  
  (all passengers are in their seats, and either the train is full or all waiting passengers have boarded).  

• The train leaves the station promptly if no passengers are waiting at the station or it has no available free seats.

• When a passenger robot arrives in a station, it first invokes the function:  
  **station wait for train(struct station * station)**  
  This function only returns when a train is in the station and there is a free seat on the train for this passenger to sit down.  

• Once the passenger is seated, it will call the function:  
  **station on board(struct station * station)**  
  to let the train know that it’s on board.  


### To run the program:
```
Open the terminal and go to project path 
Write the command "make" to compile the project files   
Write the command "./caltrain" to run the project 
```

