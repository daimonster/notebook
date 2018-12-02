      // writing on a text file  
     #include <fiostream.h>  
     int main () {  
         ofstream out("out.txt");  
         if (out.is_open())   
        {  
             out << "This is a line.\n";  
             out << "This is another line.\n";  
             out.close();  
         }  
         return 0;  
     }  
    //结果: 在out.txt中写入：  
    //This is a line.  
    //This is another line  
    // reading a text file  
   //#include <iostream.h>  
   //    #include <fstream.h>  
   //    #include <stdlib.h>  
         
       int main () {  
           char buffer[256];  
           ifstream in("test.txt");  
           if (! in.is_open())  
           { cout << "Error opening file"; exit (1); }  
           while (!in.eof() )  
           {  
               in.getline (buffer,100);  
               cout << buffer << endl;  
           }  
           return 0;  
       }  
       /*结果 在屏幕上输出  
        This is a line.  
        This is another line  
