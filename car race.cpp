
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Define a structure for Car
struct Car {
    string name;
    int speed;
};

// Function to add a car to the racing track
void addCar(queue<Car>& track, string name, int speed) {
    Car newCar = {name, speed};
    track.push(newCar);
    cout << "Car " << name << " added to the track." << endl;
}

// Function to remove a car from the racing track
void removeCar(queue<Car>& track) {
    if (track.empty()) {
        cout << "No cars on the track." << endl;
    } else {
        Car removedCar = track.front();
        track.pop();
        cout << "Car " << removedCar.name << " removed from the track." << endl;
    }
}

// Function to display the cars on the racing track
void displayCars(queue<Car>& track) {
    queue<Car> temp = track;
    cout << "Cars on the track:" << endl;
    while (!temp.empty()) {
        Car currentCar = temp.front();
        temp.pop();
        cout << "Name: " << currentCar.name << ", Speed: " << currentCar.speed << endl;
    }
}

// Function to simulate the car racing
void simulateRacing(queue<Car>& track) {
    if (track.empty()) {
        cout << "No cars on the track." << endl;
    } else {
        cout << "Racing simulation started." << endl;
        queue<Car> temp = track;
        int time = 0;
        while (!temp.empty()) {
            Car currentCar = temp.front();
            temp.pop();
            cout << "Time " << time << ": Car " << currentCar.name << " is at position " << temp.size() + 1 << endl;
            time += currentCar.speed;
        }
        cout << "Racing simulation ended." << endl;
    }
}

int main() {
    queue<Car> racingTrack;

    // Add cars to the racing track
    addCar(racingTrack, "Car1", 5);
    addCar(racingTrack, "Car2", 3);
    addCar(racingTrack, "Car3", 7);

    // Display cars on the racing track
    displayCars(racingTrack);

    // Simulate the car racing
    simulateRacing(racingTrack);

    // Remove a car from the racing track
    removeCar(racingTrack);

    // Display cars on the racing track after removal
    displayCars(racingTrack);

    return 0;
}
