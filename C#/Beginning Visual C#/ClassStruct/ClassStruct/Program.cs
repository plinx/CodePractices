using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassStruct
{
    public class cPerson
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public cPerson() { }
        public cPerson(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }
    public struct sPerson
    {
        public string Name;
        public int Age;
        public sPerson(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            cPerson cp1 = new cPerson("cPerson1", 5);
            Console.WriteLine("Name : {0}; Age : {1}", cp1.Name, cp1.Age);
            cPerson cp2 = new cPerson();
            cp2.Name = "cPerson2";
            Console.WriteLine("Name : {0}; Age : {1}", cp2.Name, cp2.Age);
            sPerson sp1 = new sPerson("sPerson1", 10);
            Console.WriteLine("Name : {0}; Age : {1}", sp1.Name, sp1.Age);
            sPerson sp2;
            sp2.Name = "sPerson2";
            sp2.Age = Convert.ToInt32("30");
            Console.WriteLine("Name : {0}; Age : {1}", sp2.Name, sp2.Age);

            Polym.Shape shape = new Polym.Shape();
            shape.Draw();
            var circle = new Polym.Circle();
            circle.Draw();
            Polym.Shape scircle = new Polym.Circle();
            scircle.Draw();

            Polym.A pa = new Polym.A();
            Polym.A pb = new Polym.B();
            Polym.A pc = new Polym.C();
            Polym.A pd = new Polym.D();
            pa.Do(); pb.Do(); pc.Do(); pd.Do();

            Polym.People people = new Polym.People { Name = "polym people", Age = 0 };
            Console.WriteLine("{0}", people.ToString());
        }
    }
}
