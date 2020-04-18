﻿using System;

namespace CauchyProblem
{
    // Розв'язування одновимірних задач Коші.
    class CauchyProgram
    {
        double a, b, h;
        int n;

        double F(double x, double y)
        {
            return Math.Cos(y - x);
        }

        public CauchyProgram(double a, double b, int n)
        {
            this.a = a;
            this.b = b;
            this.n = n;
            h = (b - a) / n;
        }

        public void EulerMethod(double x, double y, double h)
        {
            double exectY = x + 2 * Math.Atan(1 / x);
            Console.WriteLine($"Exact solution y* = {exectY} for x = {x}");

            for (int i = 0; i < 10; i++)
            {
                x = x + i * h;
                y = y + h * F(x, y);
            }

            Console.WriteLine($"Euler method\ny = {y}");
        }

        public void HeineMethod(double x, double y, double h)
        {
            double exectY = x + 2 * Math.Atan(1 / x);
            Console.WriteLine($"Exact solution y* = {exectY} for x = {x}");

            for (int i = 0; i < 10; i++)
            {
                x = x + i * h;

                var _y = y + h * F(x, y);
                y = y + (h / 2) * (F(x, y) + F(x + h, _y));

            }

            Console.WriteLine($"Heine method\ny = {y}");
        }

        public void RungeKuttaMethod(double x, double y, double h)
        {
            double exectY = x + 2 * Math.Atan(1 / x);
            Console.WriteLine($"Exact solution y* = {exectY} for x = {x}");

            for (int i = 0; i < 10; i++)
            {
                x = x + (i + 1) * h;

                var k1 = F(x, y);
                var k2 = F(x + (h / 2), y + (h / 2) * k1);
                var k3 = F(x + (h / 2), y + (h / 2) * k2);
                var k4 = F(x + h, y + h * k3);

                y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
            }

            Console.WriteLine($"Runge - Kutta method\ny = {y}");
        }
    }

    // Розв'язування систем задач Коші.
    class CauchySystemProgram
    {
        double[] Fg(double x, double y, double z)
        {
            return new double[] {
               2 * y + z,
               3 * y + 4 * z
            };
        }

        public void EulerMethod(double x, double y, double z, double h)
        {
            for (int i = 0; i < 10; i++)
            {
                x = x + i * h;

                var fg = Fg(x, y, z);

                y = y + h * fg[0];
                z = z + h * fg[1];
            }

            Console.WriteLine($"System Euler method\ny = {y}\nz = {z}");
        }

        public void HeineMethod(double x, double y, double z, double h)
        {
            for (int i = 0; i < 10; i++)
            {
                x = x + i * h;

                var fg = Fg(x, y, z);

                var _y = y + h * fg[0];
                var _z = z + h * fg[1];

                var fPlusF = Fg(x, y, z)[0] + Fg(x + h, _y, _z)[0];
                var gPlusG = Fg(x, y, z)[1] + Fg(x + h, _y, _z)[1];

                y = y + (h / 2) * fPlusF;
                z = z + (h / 2) * gPlusG;

            }

            Console.WriteLine($"System Heine method\ny = {y}\nz = {z}");
        }

        public void RungeKuttaMethod(double x, double y, double z, double h)
        {
            for (int i = 0; i < 10; i++)
            {
                x = x + (i + 1) * h;

                var k1 = Fg(x, y, z)[0];
                var l1 = Fg(x, y, z)[1];

                var k2 = Fg(x + (h / 2), y + (h / 2) * k1, z + (h / 2) * l1)[0];
                var l2 = Fg(x + (h / 2), y + (h / 2) * k1, z + (h / 2) * l1)[1];

                var k3 = Fg(x + (h / 2), y + (h / 2) * k2, z + (h / 2) * l2)[0];
                var l3 = Fg(x + (h / 2), y + (h / 2) * k2, z + (h / 2) * l2)[1];

                var k4 = Fg(x + h, y + h * k3, z + h * l3)[0];
                var l4 = Fg(x + h, y + h * k3, z + h * l3)[1];

                y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
                z = z + (h / 6) * (l1 + 2 * l2 + 2 * l3 + l4);
            }

            Console.WriteLine($"System Runge - Kutta method\ny = {y}\nz = {z}");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            CauchyProgram cauchyProgram = new CauchyProgram(a: 0, b: 1, n: 10);

            cauchyProgram.EulerMethod(1, 2.57, 0.1);
            cauchyProgram.HeineMethod(1, 2.57, 0.1);
            cauchyProgram.RungeKuttaMethod(1, 2.57, 0.1);

            CauchySystemProgram cauchySystemProgram = new CauchySystemProgram();

            cauchySystemProgram.EulerMethod(0, 0, 4, 0.01);
            cauchySystemProgram.HeineMethod(0, 0, 4, 0.01);
            cauchySystemProgram.RungeKuttaMethod(0, 0, 4, 0.01);
        }
    }
}
