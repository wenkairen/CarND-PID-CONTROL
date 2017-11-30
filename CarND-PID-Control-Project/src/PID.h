#ifndef PID_H
#define PID_H
#include <vector>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double prev_cte;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;


  /*
  * Twiddle Parameter
  */
  int iteration; // for calculating steps during the lap. 
  int steps; // for counting steps before start capturing err
  int eval_steps; // after params have settled, capture new error
  double err; // error in each ecaluation

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
