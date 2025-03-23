#include <stdio.h>

void initializeSystem(int lights[], int temperature[], int motion[], int locks[], int rooms);
void toggleLight(int lights[], int rooms);
void readTemperature(int temperature[], int rooms);
void checkMotionSensor(int motion[], int rooms);
void lockUnlockSecurity(int locks[], int rooms);
void houseStatus(int lights[], int temperature[], int motion[], int locks[], int rooms);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    int lights[rooms], temperature[rooms], motion[rooms], locks[rooms];
    
    initializeSystem(lights, temperature, motion, locks, rooms);
    
    int choice;
    do {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: toggleLight(lights, rooms); break;
            case 2: readTemperature(temperature, rooms); break;
            case 3: checkMotionSensor(motion, rooms); break;
            case 4: lockUnlockSecurity(locks, rooms); break;
            case 5: houseStatus(lights, temperature, motion, locks, rooms); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}

void initializeSystem(int lights[], int temperature[], int motion[], int locks[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;  // OFF
        temperature[i] = 22 + (i % 5);  // Assigning arbitrary temperatures
        motion[i] = 0;  // No motion
        locks[i] = 1;  // Locked
    }
    printf("System initialized. All lights OFF, doors LOCKED, no motion detected.\n");
}

void toggleLight(int lights[], int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature(int temperature[], int rooms) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
    } else {
        printf("Invalid room number.\n");
    }
}

void checkMotionSensor(int motion[], int rooms) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number.\n");
    }
}

void lockUnlockSecurity(int locks[], int rooms) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number.\n");
    }
}

void houseStatus(int lights[], int temperature[], int motion[], int locks[], int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
               lights[i] ? "ON" : "OFF", temperature[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
