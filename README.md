# IoT Smart Parking System
In the present scenario of the COVID-19 pandemic, an automatic parking system is essential. This project involves designing an IoT-based Android application to detect available parking slots in a parking space.

## Overview
Nowadays, finding vehicle parking in the city has become difficult due to busy traffic and full parking lots. The smart parking system uses technology to find parking for vehicles, saving time and fuel.

In this project, we build a smart parking system using NodeMCU and ultrasonic sensors. The sensors detect the distance to objects and help find available parking slots. The live position of the parking slot is shown on an Android app using real-time data from Google Firebase. MIT App Inventor is used to develop the Android app.

## Components Required        
### NodeMCU
### Ultrasonic Sensors (as per the number of slots needed)
### Breadboard
### Jumper Wires
### Circuit Diagram

## Connect the components as follows:
NodeMCU to Ultrasonic Sensor 1
Vin 5v -> Vcc
D0 -> Trig
D1 -> Echo
GND -> GND
NodeMCU to Ultrasonic Sensor 2
Vin 5v -> Vcc
D2 -> Trig
D3 -> Echo
GND -> GND
NodeMCU to Ultrasonic Sensor 3
Vin 5v -> Vcc
D4 -> Trig
D5 -> Echo
GND -> GND

## Firebase Setup
Sign in to Google Firebase and create a new project.
From the project dashboard, choose Database.
Create a Real-time Database and start in test mode.
Copy your Firebase Project URL (e.g., https://project-id.firebaseio.com/) and paste it into the code at FIREBASE_HOST without "https://" and "/".
Go to Project Settings > Service Account > Database Secrets.
Copy the Project Secret and paste it into the code at FIREBASE_AUTH.

## Android App Setup
Download the Smart Parking App .aia file and extract it.
Sign in to MIT App Inventor and import the .aia file.
Open the project and select FirebaseDB1 from the Components list.
In properties, paste the Firebase Project Secret in "Firebase Token" and Firebase Project URL in "FirebaseURL" (including "https://").
Ensure the Project Bucket is empty.
