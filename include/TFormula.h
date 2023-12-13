#ifndef _FORMULA_
#define _FORMULA_

#include <iostream>
#include "MyList.h"
#include "TStack.h"
using namespace std;
template <class TString>
class TFormula
{
	TList<TString> Partition(char* s) // ����� ��� ���������� ������� ������ �� ��������
	{
    TList<TString> rest;//������� ������ 
    int start = 0;//��������� �������� �������
    int length = strlen(s);//������ ����� ������
    for (int i = 0; i < length; i++)
    {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
      {
        TString N(&(s[start]), i - start);//������� ����� ������ �� ������ �� ���������
        TString R(&(s[i]), 1);//������ � ����������
        start = i + 1;
        rest.PushEnd(N);
        rest.PushEnd(R);
      }
    }
    TString K(&(s[start]), length - start);//c������ ������ �� ���������� ����� ������� ������
    rest.PushEnd(K);
    return rest;
	}


double Calculate(TList<TString> s) //�������
  {
    TStack<double> stack; //���� ��� �������� �����
    for (auto i = s.GetBegin(); i != s.GetEnd(); i++)
    {
      if (i->isNumber())
      {
        stack.Push(i->toDouble()); //��������� ����� � ����
      }
      else
      {
        double Num2 = stack.GetElem(); //�������� ������ ����� �� �����
        double Num1 = stack.GetElem(); //�������� ������ ����� �� �����
        if (*i == "+") { stack.Push(Num1 + Num2); }
        if (*i == "-") { stack.Push(Num1 - Num2); }
        if (*i == "*") { stack.Push(Num1 * Num2); }
        if (*i == "/") { stack.Push(Num1 / Num2); } 
      }
    }
    return stack.GetElem();
  }

TList<TString> ToPolish(TList<TString> s) //����� ��� �������������� ���������
  {
    TList<TString> res;//������ ���������� ��������������
    TStack<TString> stack;//������� ���� ��� ���������� �������� ��������
    for (auto i = s.GetBegin(); i != s.GetEnd(); i++)
    {
      if (i->isNumber() || *i == "(")//���� ������� ����� ��� ������, �� ����������� � ����� ������
      {
        res.PushEnd(*i);
      }
      else if (*i == ")") //���� ������� ���� ������, ����������� ��������� �������� � �����, ���� �� ���������� ���� ������
      {
        while (!stack.IsEmpty() && stack.Top() != "(")
        {
          res.PushEnd(stack.GetElem());
        }
        if (!stack.isEmpty() && stack.Top() == "(")
        {
          stack.GetElem(); //������� ����������� ������ �� �����
        }
      }
      else if (*i == "*" || *i == "/" || *i == "+" || *i == '-')
      {
        while (!stack.IsEmpty() && Prioritet(stack.Top(), *i))
        {
          res.PushEnd(stack.GetElem()); //�������� �������� � ����� ������� ����������� � ���������
        }
        stack.Push(*i); //�������� ������� �������� � ����
      }
    }
    while (!stack.IsEmpty())
    {
      res.PushEnd(stack.GetElem()); //�������� ���������� �������� � ���������
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