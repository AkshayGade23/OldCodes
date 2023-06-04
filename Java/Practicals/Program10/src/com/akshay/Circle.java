package com.akshay;

import com.area.Area;// importing class from another package.

public class Circle {
    float radius;

    Circle(float radius) {
        this.radius = radius;
    }

    void area() {
        // using method from imported class.
        System.out.println("Area of cicle = " + Area.circle(radius));
    }
}
