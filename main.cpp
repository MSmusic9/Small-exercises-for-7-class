#include <iostream>
#include <string>
#include <functional>
#include <math.h>
#include <algorithm>
#include <map>
#include <chrono>


double pattern1(float a, float b, float c){return a * (b - c * c) + b;};

double pattern2(float a, float b, float c){return pow(a * a + b, 3);};

double pattern3(float a, float b, float c){return c * (a * a * a + b * b * b);};

double pattern4(float a, float b, float c){return 5 * (2 * a + 3 * b * b) - c;};


std::map<std::string, std::function<double(float,float,float)>> patterns{
  {"a * b - a * c ^ 2 + b", pattern1}, {"(a ^ 2 + b) ^ 3", pattern2}, {"c * (a ^ 3 + b ^ 3)", pattern3}, {"5 * (2 * a + 3 * b ^ 2) - c", pattern4}
};


bool is_space(unsigned char s){
  return (s == ' ') || (s == '\t');
};


bool gen_random_expr(){
  float inp;
  auto iter = patterns.begin();
  std::advance(iter, rand() % 4);
  std::string s = iter->first;
  std::cout << "Решите быстрым способом (округлить вниз до десятых):\n";
  /* main function code */
  float a = (rand() % 25) / 5.0f, b = (rand() % 25) / 5.0f, c = (rand() % 25) / 5.0f;
  float res = roundf((patterns[s])(a, b, c) * 10.0f) / 10.0f;
  for (int pos = 0; pos < s.size(); pos++){
    switch (s[pos]){
      case 'a':
        std::cout << a;
        break;
      case 'b':
        std::cout << b;
        break;
      case 'c':
        std::cout << c;
        break;
      default: std::cout << s[pos];
    }
  };
  /* main code ends :( */
  std::cout <<  " = ";
  std::cin >> inp;
  std::cout << "\n";
  return res == inp;
};


bool gen_equal_system(){
  std::string first_yr, sec_yr;
  float x, y, res_x, res_y, first_num = (rand() % 25) / 5.0f, sec_num = (rand() % 25) / 5.0f;
  float coef_x = (rand() % 25) / 5.0f, coef_y = (rand() % 25) / 5.0f, coef_x2 = (rand() % 25) / 5.0f, coef_y2 = (rand() % 25) / 5.0f;
  std::cout << "Решите  систему уравнений:\n";
  std::cout << "{ " << coef_x << "x + " << coef_y << "y = " << first_num << "\n";
  std::cout << "{ " << coef_y2 << "y - " << coef_x2 << "x = " << sec_num << "\n";
  std::cout << "x = ";
  std::cin >> x;
  std::cout << "y = ";
  std::cin >> y;
  std::cout << "\n\n";
  return (x == res_x) || (y == res_y);
};


int main(){
  srand(time(0));
  std::cout << "Задания по математике, 7 класс\n";
  std::cout << "(Возведение в степень делать через 'a ^ 2')\n\n\n";
  int result = 0;
  std::string ab_2, ab_3, a_m_b, a_p_b3;
  std::cout << "(a + b) ^ 2 = ";
  std::getline(std::cin, ab_2);
  std::cout << "(a + b) ^ 3 = ";
  std::getline(std::cin, ab_3);
  std::cout << "a^2 - b^2 = ";
  std::getline(std::cin, a_m_b);
  std::cout << "a^3 + b^3 = ";
  std::getline(std::cin, a_p_b3);
  std::cout << "\n\n";
  std::remove_if(ab_2.begin(), ab_2.end(), is_space);
  std::remove_if(ab_3.begin(), ab_3.end(), is_space);
  std::remove_if(a_m_b.begin(), a_m_b.end(), is_space);
  std::remove_if(a_p_b3.begin(), a_p_b3.end(), is_space);
  if ((ab_2 == "a^2+2ab+b^2") || (ab_2 == "a^2+2*a*b+b^2")) result++;
  if ((ab_3 == "a^3+3*a^2*b+3*a*b^2+b^3") || (ab_3 == "a^3+(3*a^2*b)+(3*a*b^2)+b^3")) result++;
  if ((a_m_b == "(a-b)(a+b)") || (a_m_b == "(a-b)*(a+b)")) result++;
  if ((a_p_b3 == "(a+b)(a^2-2ab+b^2)") || (a_p_b3 == "(a+b)*(a^2-2ab+b^2)") || (a_p_b3 == "(a+b)*(a^2-2*a*b+b^2)") || (a_p_b3 == "(a+b)(a^2-2*a*b+b^2)")) result++;
  for (int i = 0; i < 4; i++){
    if (gen_random_expr()) result++;
  };
  std::cout << "\n";
  if (gen_equal_system()) result++;
  if (gen_equal_system()) result++;
  std::cout << "\nИтоговый результат: " << result << "/10\n";
}