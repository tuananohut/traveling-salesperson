# Traveling Salesperson Problem (TSP) Visualization

https://youtu.be/nqyQTMZwQA8

A C++ and SFML application that visualizes a brute-force solution to the classic **Traveling Salesperson Problem (TSP)**, a famous NP-hard problem in computer science and combinatorial optimization.

---

## Project Overview

The goal of this project was to develop a deeper, intuitive understanding of algorithmic complexity by visualizing it. The Traveling Salesperson Problem asks: "Given a list of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?"

This application generates a random set of points (cities) and then systematically calculates every possible route to find the absolute shortest one. The visualization allows you to see the algorithm's progress in real-time as it explores the vast search space of potential paths.

---

## Key Features & Implemented Concepts

* **Problem Setup:** The simulation begins by creating a user-defined number of random points on the screen.
* **Brute-Force Algorithm:** The core of the solver is a lexicographical permutation algorithm. It iterates through every single possible ordering of the cities to guarantee finding the optimal solution.
* **Real-time Visualization:** The current best path found so far is drawn in one color, while the path currently being tested is drawn in another, providing a clear visual distinction between the optimal and the exploratory paths.
  
---

## What I Learned: The Immensity of NP-Hard Problems

This project was a humbling and incredibly insightful lesson in the practical meaning of **algorithmic complexity**.

* **Visualizing Combinatorial Explosion:** The most profound takeaway was seeing the "combinatorial explosion" happen live. The simulation runs instantly with 5 or 6 cities. With 10 cities (3.6 million permutations), it starts to take a noticeable amount of time. With just 12 cities (nearly half a billion permutations), the wait becomes significant. This provided a visceral understanding of why brute-force is not a feasible solution for real-world TSP instances.

* **The Power of Algorithms:** I learned to appreciate why more advanced heuristic algorithms (like Genetic Algorithms or Simulated Annealing) are necessary for NP-hard problems. This project perfectly illustrates the *problem* that those more complex algorithms are designed to *solve*.

* **Practical C++ Application:** This was a fantastic exercise in using C++ for algorithmic tasks. 

---

## How to Build & Run

This project requires **Visual Studio 17 2022** and **CMake 3.8+**.

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/tuananohut/Traveling-Salesperson-Problem-Visualization.git
    ```
2.  **Create and Navigate to the Build Directory:**
    ```bash
    mkdir build
    cd build
    ```
3.  **Configure with CMake:**
    ```bash
    cmake ..
    ```
4.  **Build and Run from Visual Studio:**
    * Open the generated `TravelingSalesperson.sln` file located in the `build` directory.
    * Set the "TravelingSalesperson" project as the startup project.
    * **DLL Fix (if necessary):** If you encounter a DLL error upon running, navigate to the `Dependencies/bin` folder in the root of the repository. Copy all `.dll` files from this folder and paste them into your `build/Debug` directory (next to the `.exe` file).
    * Build and run the project (F5).

---

## Acknowledgements

The concept and implementation were guided by these excellent educational resources:
* **The Coding Train Tutorial:** [Coding Challenge #35: Traveling Salesperson](https://www.youtube.com/watch?v=BAejnwN4Ccw)
* **Wikipedia:** [Travelling salesman problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
