#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // inintialzie the value
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    prev_cte = 0.0;
  
    iteration= 1;
    steps = 50;
    eval_steps =100; 
    err = 0;
}

void PID::UpdateError(double cte) {

  if (iteration == 1) {
    prev_cte = cte;
  }

  double diff_cte = cte - prev_cte;
  p_error = cte;
  i_error += cte;
  d_error = diff_cte;
  prev_cte = cte;

  int eval_a = iteration % steps;
  int eval_b = iteration % (steps+eval_steps);

  if ( eval_b > steps) {
    err += cte * cte;
  }
  // stop condition
  if ( iteration == (steps + eval_steps)) {
    cout << "best err : " << err << endl;
  }
  iteration ++;
}

double PID::TotalError() {

  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

