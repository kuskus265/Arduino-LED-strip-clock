using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO.Ports;
namespace Hodiny
{
    class Program
    {
        static SerialPort _serialPort;
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            int p = 0;
            bool vstup = true;
            _serialPort = new SerialPort();
            Console.WriteLine("Dostupne porty:");
            Console.WriteLine();
            string[] porty = SerialPort.GetPortNames();
            if (porty.Length == 0)
            {
                Console.WriteLine("žádné porty nenalezeny");
                Console.Write("Stiskněte libovolnou lkávesu pro ukončení programu");
                Console.ReadKey();
                Environment.Exit(1);
            }
            else
            {
                foreach (string port in porty)
                {
                    Console.WriteLine("{0}.  {1}", p, port);
                    p++;
                }
            }
          
            Console.WriteLine();
            Console.Write("Vyberte port na který je připojeno Arduino: ");
            while(vstup){
                try
                {
                    _serialPort.PortName = porty[Convert.ToInt32(Console.ReadLine())];
                    vstup = false;
                }
                catch (FormatException)
                {
                    Console.WriteLine("špatně zadaná hodnota, zkuste to znovu");

                }
                
            }
            _serialPort.BaudRate = 9600;
            _serialPort.Open();
            while(true)
            {
                Console.WriteLine("Synchornizace času");
                String date = DateTime.Now.ToString("HH:mm:ss");
                _serialPort.WriteLine(date);
                Console.WriteLine("Hotovo, další za 1 minutu");
                _serialPort.Close();
                Thread.Sleep(60000);
                _serialPort.Open();
            }


        }
    }
}
