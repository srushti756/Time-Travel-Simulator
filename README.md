# Simulating Time Travel with Linked List Nodes

## Project Title

Simulating Time Travel with Linked List Nodes: Managing Past and Future Events using Stack and Queue

## Introduction

This project is a simple Time Travel Simulator developed using C++.

The project demonstrates the use of Linked List Nodes along with Stack and Queue data structures.

The Stack is used to store past events, while the Queue is used to manage future events.

The user can travel forward and backward between different events using the menu provided in the program.

## Objectives

- To understand the concept of Linked List Nodes.
- To implement Stack using Linked List.
- To implement Queue using Linked List.
- To manage past events using Stack.
- To manage future events using Queue.
- To understand the practical application of data structures.

## Data Structures Used

### 1. Linked List

Each event is stored inside a Node.

Each Node contains:

- Event name
- Pointer to the next Node

### 2. Stack

Stack follows the LIFO principle.

LIFO means:

Last In First Out

The Stack stores past events.

Operations used:

- Push
- Pop

### 3. Queue

Queue follows the FIFO principle.

FIFO means:

First In First Out

The Queue stores future events.

Operations used:

- Enqueue
- Dequeue

## Working of the Project

Initially, the program contains some future events.

The current event is set to "Present Day".

### Travel Forward

When the user selects Travel Forward:

1. The current event is pushed into the Stack.
2. The next future event is removed from the Queue.
3. The removed event becomes the current event.

### Travel Back

When the user selects Travel Back:

1. The current event is added to the Future Queue.
2. The previous event is removed from the Past Stack.
3. The removed event becomes the current event.

### Add Future Event

The user can add a new event to the Future Queue.

## Features

- Menu-driven program
- Linked List implementation
- Stack implementation
- Queue implementation
- Travel forward
- Travel backward
- Undo time travel
- Add new future events

## Technologies Used

- C++
- Linked List
- Stack
- Queue

## Conclusion

The Time Travel Simulator demonstrates how basic data structures can be used to model a real-life concept.

The Stack manages past events using the LIFO principle, while the Queue manages future events using the FIFO principle.

The project provides a simple and practical understanding of Linked Lists, Stacks and Queues.
