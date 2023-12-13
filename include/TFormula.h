#ifndef _FORMULA_
#define _FORMULA_

#include <iostream>
#include "MyList.h"
#include "TStack.h"
using namespace std;
template <class TString>
class TFormula
{
	TList<TString> Partition(char* s) // метод для разделение входной строки на элементы
	{
    TList<TString> rest;//создаем список 
    int start = 0;//начальное значение индекса
    int length = strlen(s);//узнаем длину строки
    for (int i = 0; i < length; i++)
    {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
      {
        TString N(&(s[start]), i - start);//создаем новую строку от начала до оператора
        TString R(&(s[i]), 1);//строка с оператором
        start = i + 1;
        rest.PushEnd(N);
        rest.PushEnd(R);
      }
    }
    TString K(&(s[start]), length - start);//cоздаем строку из оставшейся части входной строки
    rest.PushEnd(K);
    return rest;
	}


double Calculate(TList<TString> s) //считает
  {
    TStack<double> stack; //стек для хранения чисел
    for (auto i = s.GetBegin(); i != s.GetEnd(); i++)
    {
      if (i->isNumber())
      {
        stack.Push(i->toDouble()); //добавляем числа в стек
      }
      else
      {
        double Num2 = stack.GetElem(); //получаем второе число из стека
        double Num1 = stack.GetElem(); //получаем первое число из стека
        if (*i == "+") { stack.Push(Num1 + Num2); }
        if (*i == "-") { stack.Push(Num1 - Num2); }
        if (*i == "*") { stack.Push(Num1 * Num2); }
        if (*i == "/") { stack.Push(Num1 / Num2); } 
      }
    }
    return stack.GetElem();
  }

TList<TString> ToPolish(TList<TString> s) //метод для преобразования выражения
  {
    TList<TString> res;//хранит результаты преобразований
    TStack<TString> stack;//создаем стек для временного хранения операций
    for (auto i = s.GetBegin(); i != s.GetEnd(); i++)
    {
      if (i->isNumber() || *i == "(")//если элемент число или скобка, он добавляется в конец списка
      {
        res.PushEnd(*i);
      }
      else if (*i == ")") //если элемент закр скобка, выполняется обработка операций в стеке, пока не встретится откр скобка
      {
        while (!stack.IsEmpty() && stack.Top() != "(")
        {
          res.PushEnd(stack.GetElem());
        }
        if (!stack.isEmpty() && stack.Top() == "(")
        {
          stack.GetElem(); //удаляем открывающую скобку из стека
        }
      }
      else if (*i == "*" || *i == "/" || *i == "+" || *i == '-')
      {
        while (!stack.IsEmpty() && Prioritet(stack.Top(), *i))
        {
          res.PushEnd(stack.GetElem()); //помещаем операции с более высоким приоритетом в результат
        }
        stack.Push(*i); //помещаем текущую операцию в стек
      }
    }
    while (!stack.IsEmpty())
    {
      res.PushEnd(stack.GetElem()); //помещаем оставшиеся операции в результат
    }
    return res;
  }

  bool Prioritet(const TString& op1, const TString& op2)
  {
    int precedence1, precedence2;
    if (op1 == "*" || op1 == "/") {
      precedence1 = 2;
    }
    else if (op1 == "+" || op1 == "-") {
      precedence1 = 1;
    }
    else {
      precedence1 = 3;
    }

    if (op2 == "*" || op2 == "/") {
      precedence2 = 2;
    }
    else if (op2 == "+" || op2 == "-") {
      precedence2 = 1;
    }
    else {
      precedence2 = 3;
    }
    if (precedence1 >= precedence2)
    {
      return true;
    }
    else false;
  }

};
#endif