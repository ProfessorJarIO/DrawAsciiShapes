# DrawAsciiShapes
Learn how to draw shapes to the console using ASCII. Will cover: Circles, Triangles, Trapezoids

## Draw Circle to Console
Circle Equation: (x - h)² + (y - k)² = r²

This equation will be helpful for us to know when drawing a circle onto the console.

We need to isolate and find the "r" variable, so we take the sqrt( (x-h)^2 + (y-k)^2 ).

The reason why this is helpful is because we will be taking both the x and y coordinates and sub it into this equation. Then we check if the value we get is part of the circle's perimeter. 

Because I am using `int` data type in this program when iterating both x and y, the resultant will not always be exactly 5, which is why we use a TOLERANCE variable to have a range of numbers that are acceptable.

The rest is simple, if the range is acceptable given the tolerance, we put a star to show it's part of the circle. If it's not within the range of tolerance, we put a space.

## Draw a Triangle to Console
I believe that a triangle is easier to draw, simply because we are keeping track of only 2 variables, 1 that keeps track of how many spaces we need to put, and the other keeping track of how many stars to put.

If we increment one and decrement the other variable, we will eventually get a triangle. This will only give us a right triangle, but we can fix this by multiplying the number of stars we need to put twice to give us an equilateral triangle.

## Draw a Trapezoid to Console
A trapezoid is a triangle + rectangle/square + triangle

Because we already know how to draw a triangle, this should be pretty easy.

We first draw first row of the right triangle, then the first row of the rectangle, and the first row of the last triangle. We continue doing this until we get through the whole shape.

# Resources
> https://www.cuemath.com/geometry/equation-of-circle/
> 
> https://www.mathsisfun.com/algebra/circle-equations.html
