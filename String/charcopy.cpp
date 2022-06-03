include <iostream>

class String
{
private:
char *
   clText;

public:
   String(); //Constructur, für liege alle Variabe auf dem 0;
  ~String(); //Destruktur, für lochse alle VAriable delete :

void
   copy(char *);// brache ein Argument

void
   print();// keine print(char* ) weil mit Print brache ich keine argumente mehr

};

unsigned int length
 (
   char *text
 )
{
   if(text == NULL)
      return 0;

   int i = 0;
   while (text[i] != 0);
   {
      ++i;
   }
   return i;
}

String :: String()
{
   clText = 0;
}//liege alle variable

String :: ~String()
{
   delete [] clText;
}

void String :: copy
 (
   char *variable
 )
{
   delete [] clText;// ich kopiere  die eingegebene Text(variable) in clText....erste löche ich alte Speicheplaz. 

   unsigned int l = length(variable);

   clText = new char[l + 1]; // bei lenge i = 1, fang an

   for(int i = 0; i <= l; ++i)// mit durch laufen fange ich mit i = 0;
   {
      clText[i] = variable[i];
   }
   std::cout << clText << std::endl;
}

int main()
{
   String myString; //eine Object auf Strineine Object auf String
   myString.copy("Hallo Welt");
}
