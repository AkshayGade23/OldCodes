package com.akshay;

import com.area.Area; // importing class from another package.

public class Rectangle {
    float length, breadth, height;

    Rectangle(float length, float breadth, float height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    void area() {
        // using method from imported class.
        System.out.println("Area of rectangle = " + Area.rectangle(length, breadth));
    }
}
