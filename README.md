# Intelligent Room Energy Optimization System

---

## 1. Project Overview

The Intelligent Room Energy Optimization System is an embedded machine learning project that combines real-time sensing, scheduling, energy management, and ML-derived decision logic to optimize room energy usage.

The system continuously monitors environmental conditions using multiple sensors and processes this data through a structured firmware architecture. A Decision Tree model is trained offline in Python, and the learned rules are deployed on an ESP32 microcontroller as lightweight embedded logic capable of making real-time decisions without cloud connectivity.

This project demonstrates the complete workflow from data collection and machine learning model development to deployment on an embedded edge device.

---

## 2. Objectives

* Monitor room environmental conditions in real time.
* Collect sensor data for intelligent decision making.
* Implement a modular embedded firmware architecture.
* Train a machine learning model using collected data.
* Convert trained ML logic into embedded decision rules.
* Optimize room energy usage through autonomous mode selection.
* Demonstrate edge AI execution on a microcontroller platform.

---

## 3. Hardware Components

| Component    | Function                       |
| ------------ | ------------------------------ |
| ESP32        | Main Processing Unit           |
| DHT11        | Temperature & Humidity Sensing |
| LDR          | Ambient Light Detection        |
| PIR Sensor   | Motion Detection               |
| OLED Display | System Status Visualization    |
| LEDs         | Energy State Indicators        |

---

## 4. System Architecture

Sensor Layer

* DHT11 Sensor
* LDR Sensor
* PIR Motion Sensor

↓

Sensor Manager

↓

Scheduler

↓

ML Decision Module

↓

Energy Manager

↓

Output Layer

* OLED Display
* LED Indicators
* Logger

---

## 5. Firmware Architecture

The project follows a modular firmware design to improve maintainability and scalability.

### Sensor Manager

Responsible for:

* Reading sensor values
* Validating sensor data
* Providing a unified interface for the system

### Scheduler

Responsible for:

* Periodic task execution
* Sensor updates
* Display refresh
* Logging operations
* Decision evaluation timing

### ML Decision Module

Responsible for:

* Implementing Decision Tree derived rules
* Evaluating current environmental conditions
* Generating intelligent system decisions

### Energy Manager

Responsible for:

* Managing operating modes
* Applying optimization policies
* Controlling overall system behavior

### Logger

Responsible for:

* Recording sensor readings
* Storing operational information
* Supporting future dataset improvements

### OLED Display

Responsible for displaying:

* Temperature
* Humidity
* Light level
* Motion status
* Current system mode

---

## 6. Machine Learning Workflow

The machine learning pipeline consists of the following stages:

### Data Collection

Sensor data is gathered from the embedded system and organized into a structured dataset.

### Data Preprocessing

The collected data is cleaned and prepared for training.

### Feature Selection

Relevant sensor features are selected for model development.

### Model Training

A Decision Tree model is trained using Python.

### Rule Extraction

Decision rules are extracted from the trained model.

### Embedded Deployment

The extracted rules are implemented directly in ESP32 firmware, enabling lightweight edge execution.

---

## 7. Operating Modes

### ACTIVE MODE

Conditions:

* Motion detected
* High room activity

Behavior:

* Full system responsiveness
* Maximum functionality

### IDLE MODE

Conditions:

* Reduced activity

Behavior:

* Moderate energy usage
* Continued monitoring

### ENERGY SAVING MODE

Conditions:

* Extended inactivity

Behavior:

* Reduced power consumption
* Energy optimization prioritization

---

## 8. Key Features

* Real-time environmental monitoring
* Embedded machine learning decision logic
* Scheduler-based task management
* Energy optimization framework
* OLED user interface
* Data logging system
* Modular firmware architecture
* Edge AI deployment
* Cloud-independent operation

---

## 9. Results

The project successfully demonstrates how machine learning models can be trained offline and deployed as efficient embedded decision systems.

The final system combines:

* Real-time sensing
* Intelligent decision making
* Scheduler-based execution
* Energy management
* Embedded deployment

into a single integrated edge AI solution.

---

## 10. Future Enhancements

* FreeRTOS-based task scheduling
* Wi-Fi connectivity
* MQTT integration
* Cloud dashboard support
* Power consumption analytics
* Online data collection
* Advanced machine learning models

---

