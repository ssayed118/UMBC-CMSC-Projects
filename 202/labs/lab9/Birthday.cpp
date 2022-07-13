#include "Birthday.h"

Birthday::Birthday(string name,
                 double burnRate,
                 bool isNoExtinguish)
  : Candle(name, burnRate)
{
  m_isNoExtinguish = isNoExtinguish;
}

bool Birthday::GetIsNoExtinguish()
{
  return m_isNoExtinguish;
}

void Birthday::SetIsNoExtinguish(bool isNoExtinguish){
  m_isNoExtinguish = isNoExtinguish;
}

string Birthday::SetLit(bool isLit){
  //  m_isLit = isLit;
  
  if (m_isNoExtinguish){
    cout << "You cannot blow the birthday candle out!" << endl;		
    //    return "Yes";
  }
  /* else */
  return "No";

  if(isLit == true){
    m_isLit = isLit;
    return "Yes";}
  
  return "No";
}
