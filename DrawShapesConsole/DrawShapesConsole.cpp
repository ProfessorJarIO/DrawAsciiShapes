#include <iostream>
#include <cmath>

// Tolerance will be a value that will be used to check other numbers around a value as valid. We don't always need to be percise, especially since we are dealing with small numbers here.
#define TOLERANCE 0.5

/*
The general equation for a circle with center (h, k) 
and radius r is (x - h)² + (y - k)² = r². This equation 
describes all points (x, y) that are a distance of r from the center (h, k)

* - When trying to figure out how to draw the perimeter of the circle, we have to use the circle equation  (x - h)² + (y - k)² = r².
* We are trying to isolate the radius, since that is the only variable that will give us an indicator whether or not we are close to the actual circle or not.
* When substituting the numbers in for x, h, y, k to solve for r, the number we get will not always be exactly it. That's why we have a tolerance (also bc we are using ints).
* Once we figure out that the x and y value associated at that point is apart of the circle, we simply fill it in with ASCII, the parts that aren't are filled with a space
*/
void DrawCircle(int h=50, int k=50, int r=50) {
    // Because the radius is half of the full circle, the full image will always be 2r. 2r*2r in this case for the full ascii image dimensions
    // Only problem here is if h and k are outside the boundaries of this area. That's when it become a big issue since we can no longer see the whole circle.
    int diameter = r * 2;

    // Like with all images, we go by row by row. Think about how you would create a square.
    for (int y = 0; y <= diameter; y++) {
        // Now we output each individual column for that row
        for (int x = 0; x <= diameter; x++) {
            // Now our logic needs to find out if the current position we are in is actually apart of the circle
            // Remember our equation...
            double tmp_r = sqrt( pow((double)(x - h), 2.0) + pow((double)(y - k), 2.0) ); // We are solving for "r" here, if it's around a 5, that means it's part of our circle is my theory

            //std::cout << tmp_r; DEBUGGING
            // The value we get should be around the 5 area, like 4.6,4.7,4.8... This is a small circle, so accuracies may be oversimplfied?
            if (tmp_r > r - TOLERANCE && tmp_r < r + TOLERANCE) {
                std::cout << "*";
                //std::cout << tmp_r; DEBUGGING
            }
            else {
                std::cout << " ";
                //std::cout << "( " << tmp_r << " x " << x << " y " << y << " )"; DEBUGGING

            }
        }
        std::cout << "\n";
    }


}


/*
* The only difference here is in the "if" conditional. In the function above, I only wanted the perimeter.
* This one, however, I allowed values of tmp_radius that were under the radius, plus the tolerance, meaning that it's inside the circle, to be added with ascii values.
* Of course, I could create a function that for any tmp_radius that are greater than the radius + the tolerance to be added ASCII characters, thereby allowing everything
* but the circle to be highlighted, in fact, let's do it to to show off!
*/ 
void DrawCircleFillVoid(int h = 50, int k = 50, int r = 50) {
    // Because the radius is half of the full circle, the full image will always be 2r. 2r*2r in this case for the full ascii image dimensions
    // Only problem here is if h and k are outside the boundaries of this area. That's when it become a big issue since we can no longer see the whole circle.
    int diameter = r * 2;

    // Like with all images, we go by row by row. Think about how you would create a square.
    for (int y = 0; y <= diameter; y++) {
        // Now we output each individual column for that row
        for (int x = 0; x <= diameter; x++) {
            // Now our logic needs to find out if the current position we are in is actually apart of the circle
            // Remember our equation...
            double tmp_r = sqrt(pow((double)(x - h), 2.0) + pow((double)(y - k), 2.0)); // We are solving for "r" here, if it's around a 5, that means it's part of our circle is my theory

            //std::cout << tmp_r; DEBUGGING
            // The value we get should be around the 5 area, like 4.6,4.7,4.8... This is a small circle, so accuracies may be oversimplfied?
            if (tmp_r < r + TOLERANCE) {
                std::cout << "*";
                //std::cout << tmp_r; DEBUGGING
            }
            else {
                std::cout << " ";
                //std::cout << "( " << tmp_r << " x " << x << " y " << y << " )"; DEBUGGING

            }
        }
        std::cout << "\n";
    }


}

// Yay!
void DrawCircleOutsideVoid(int h = 50, int k = 50, int r = 50) {
    // Because the radius is half of the full circle, the full image will always be 2r. 2r*2r in this case for the full ascii image dimensions
    // Only problem here is if h and k are outside the boundaries of this area. That's when it become a big issue since we can no longer see the whole circle.
    int diameter = r * 2;

    // Like with all images, we go by row by row. Think about how you would create a square.
    for (int y = 0; y <= diameter; y++) {
        // Now we output each individual column for that row
        for (int x = 0; x <= diameter; x++) {
            // Now our logic needs to find out if the current position we are in is actually apart of the circle
            // Remember our equation...
            double tmp_r = sqrt(pow((double)(x - h), 2.0) + pow((double)(y - k), 2.0)); // We are solving for "r" here, if it's around a 5, that means it's part of our circle is my theory

            //std::cout << tmp_r; DEBUGGING
            // The value we get should be around the 5 area, like 4.6,4.7,4.8... This is a small circle, so accuracies may be oversimplfied?
            if (tmp_r > r - TOLERANCE) {
                std::cout << "*";
                //std::cout << tmp_r; DEBUGGING
            }
            else {
                std::cout << " ";
                //std::cout << "( " << tmp_r << " x " << x << " y " << y << " )"; DEBUGGING

            }
        }
        std::cout << "\n";
    }


}

/* 
* A trapezoid is just: triangle --> rectangle/square --> triangle
*/
void DrawTrapezoid(int base2=10, int height=5) {
    // How about, the triangle will be contingent on the height. So if the height was 8, the base of the triangle will also be 8.
    int numStars = 1;
    int tmpBase = height;

    for (int y = 0; y < height; y++) {
        for (int space = 0; space < tmpBase; space++) {
            std::cout << " ";
        }

        // *2 for an equalaterial triangle
        // numStars alone for a right triangle
        for (int star = 0; star < numStars; star++) {
            std::cout << "*";
        }

        // Now we build the rectangle
        for (int starRect = 0; starRect < base2; starRect++) {
            std::cout << "*";
        }

        // Now we build the last triangle
        for (int star = 0; star < numStars; star++) {
            std::cout << "*";
        }

        std::cout << "\n";
        numStars += 1;
        tmpBase -= 1;

    }




    std::cout << "\n";
    numStars += 1;
    tmpBase -= 1;
    
}

/*
* Creating a triangle isn't too difficult. We just need to create 2 variables that keeps track of how many spaces and stars we need to create.
* We want to increment the amount of stars the further we go down each row. We also want to decrement the number of spaces as we go down each row.
* First, we put spaces (use for loop) then we put the stars (for loop), easy enough.
*/ 
void DrawTriangle(int width=10) {
    // Base of triangle will be at bottom. 
    //int wide = base * 2;
    int numStars = 1;
    int tmpBase = width;

    for (int y = 0; y < width; y++) {
        for (int space = 0; space < tmpBase; space++) {
            std::cout << " ";
        }

        // *2 for an equalaterial triangle
        // numStars alone for a right triangle
        for (int star = 0; star < numStars*2; star++) {
            std::cout << "*";
        }

        std::cout << "\n";
        numStars += 1;
        tmpBase -= 1;

    }

}

int main()
{
    DrawTrapezoid();
    DrawCircle(25, 25, 25);
    DrawTriangle(5);
}