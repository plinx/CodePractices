using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassStruct
{
    class Polym
    {
        public class Shape
        {
            public virtual void Draw()
            {
                Console.WriteLine("Shape draw.");
            }
        }

        public class Circle : Shape
        {
            public override void Draw()
            {
                Console.WriteLine("Circle draw.");
                //base.Draw();
            }
        }

        public class A
        {
            public virtual void Do() { Console.WriteLine("virtual Do()"); }
        }
        public class B : A
        {
            public override void Do() { Console.WriteLine("override Do()"); }
        }
        public class C : B
        {
            public sealed override void Do() { Console.WriteLine("sealed override Do()"); }
        }
        public class D : C
        {
            public void Do() { Console.WriteLine("finaly Do()"); }
        }
        public class People
        {
            public string Name { get; set; }
            public int Age { get; set; }

            public override string ToString()
            {
                return "Name : " + Name + "; Age :" + Age;
            }
        }
    }
}
