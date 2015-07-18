using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Array
{
    class Program
    {
        static void ChangeArray(int[] arr)
        {
            arr = (arr.Reverse()).ToArray();
            foreach (var i in arr)
                Console.Write("{0} ", i);
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            int[] arr1 = new int[5];
            arr1 = new int[6];
            int[] arr2 = new int[] { 1, 3, 5, 7 };
            int[] arr3 = { 1, 3, 5, 7 };
            Console.WriteLine("Array length : {0}.", arr1.Length);

            int[,] marr1 = new int[2, 3];
            marr1[0, 1] = 1;
            Console.WriteLine("Array dimensions : {0}.", marr1.Rank);
            Console.WriteLine("marr1[0] : {0}.", marr1[0, 1]);
            int[,] arr2D = new int[,] { { 1, 2 }, { 3, 4 } };

            Console.WriteLine("arr2D[0, 0] : {0}.", arr2D[1, 0]);
            int[][] jaggedArray = new int[3][];
            jaggedArray[0] = new int[5];
            jaggedArray[1] = new int[3];
            jaggedArray[2] = new int[1];

            foreach (var i in arr2)
                Console.Write("{0} ", i);
            Console.WriteLine();
            ChangeArray(arr2);
            foreach (var i in arr2)
                Console.Write("{0} ", i);
            Console.WriteLine();

            var sarr1 = new[] { "hello", null, null, "world" };
            foreach (var s in sarr1)
                Console.Write("{0} ", s);
            Console.WriteLine();

            var contacts = new[]{
                new {
                    Name = "Hello",
                    Phone = new[] {"123456", "67890"}
                },
                new {
                    Name = "World",
                    Phone = new[] {"13579"}
                }
            };

            foreach (var c in contacts)
            {
                Console.Write("Name : {0}, Phone : ", c.Name);
                foreach (var p in c.Phone)
                    Console.Write("{0} ", p);
                Console.WriteLine();
            }
        }
    }
}
