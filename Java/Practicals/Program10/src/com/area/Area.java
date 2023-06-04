package com.area;

public class Area {
    static public float rectangle(float length, float breadth) {
        return length * breadth;
    }

    static public float sqaure(float length) {
        return length * length;
    }

    static public float triangle(float base, float height) {
        return 0.5f * base * height;
    }

    static public float circle(float radius) {
        return 22 / 7 * radius * radius;
    }
}
