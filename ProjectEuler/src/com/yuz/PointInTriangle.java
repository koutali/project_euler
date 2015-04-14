package com.yuz;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class PointInTriangle {
	private static Scanner scanner;

	// formula based on determinant calculation
	public static int area(Point a, Point b, Point c) {
		return Math.abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y));
	}

	public static void main(String[] args) {

		try {
			scanner = new Scanner(new File("p102_triangles.txt"));

			int numberOfPointsInsideTriangle = 0;
			Point origin = new Point(0, 0);
			while (scanner.hasNextInt()) {
				Point a = new Point(scanner.nextInt(), scanner.nextInt());
				Point b = new Point(scanner.nextInt(), scanner.nextInt());
				Point c = new Point(scanner.nextInt(), scanner.nextInt());

				int areaTotal = area(a, b, c);
				int areaSub1 = area(a, b, origin);
				int areaSub2 = area(a, origin, c);
				int areaSub3 = area(origin, b, c);

				if (areaTotal == (areaSub1 + areaSub2 + areaSub3)) {
					++numberOfPointsInsideTriangle;
				}
			}

			System.out.println("Number of points inside triangle: "
					+ numberOfPointsInsideTriangle);
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
	}

}
