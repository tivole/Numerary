"""
File                    odedopri.py
 
Synopsis
      double odedopri(double (*fxy)(double x, double y),
                      double x0, double y0, double x1, double tol,
                      double hmax,  double hmin, int maxiter)
 
Parameters
      fxy               Input: derivative function y' = f(x, y)
                           y is the dependent variable, x is the independent
                           variable
      x0, y0            Input: initial points, x0 <= x <= x1    y(x0) = y0
      x1                Input: final value of x
      tol               Input: tolerance
      hmax              Input: maximum step size
      hmin              Input: minimum step size
      maxiter           Input: maximum number of iterations
      flag              Input: return flag
                           0   no errors
                           1   hmin exceeded
                           2   maximum iterations exceeded
 
Return value
      value of y at last step x
 
Description
      The routine odedopri() implements the Dormand-Prince method of
      solving an ordinary differential equation of the first order
      y' = f(x,y).
 
Reference
      The coefficients were obtained from
 
          E.Hairer, S.P.Norsett and G.Wanner[1991],
             "Solving Differential Equations I, Nonstiff Problems",
             2e, Springer-Verlag, p. 178
 
WARNING
      Check the flag after calling this routine!
 
Revisions
      1998.05.02      first version
"""
 
def odedopri(fxy,  x0,  y0,  x1,  tol,  hmax,  hmin,  maxiter):
       # we trust that the compiler is smart enough to pre-evaluate the
       # value of the constants.
       a21  =  (1.0/5.0)
       a31  = (3.0/40.0)
       a32  = (9.0/40.0)
       a41  = (44.0/45.0)
       a42   = (-56.0/15.0)
       a43   = (32.0/9.0)
       a51  =  (19372.0/6561.0)
       a52    =(-25360.0/2187.0)
       a53   = (64448.0/6561.0)
       a54   = (-212.0/729.0)
       a61   = (9017.0/3168.0)
       a62   = (-355.0/33.0)
       a63   = (46732.0/5247.0)
       a64  = (49.0/176.0)
       a65  = (-5103.0/18656.0)
       a71  = (35.0/384.0)
       a72  = (0.0)
       a73  = (500.0/1113.0)
       a74  = (125.0/192.0)
       a75  = (-2187.0/6784.0)
       a76  = (11.0/84.0)
 
       c2   = (1.0 / 5.0)
       c3   = (3.0 / 10.0)
       c4   = (4.0 / 5.0)
       c5   = (8.0 / 9.0)
       c6   = (1.0)
       c7   = (1.0)
 
       b1   = (35.0/384.0)
       b2   = (0.0)
       b3   = (500.0/1113.0)
       b4   = (125.0/192.0)
       b5   = (-2187.0/6784.0)
       b6   = (11.0/84.0)
       b7   = (0.0)
 
       b1p  = (5179.0/57600.0)
       b2p  = (0.0)
       b3p  = (7571.0/16695.0)
       b4p  = (393.0/640.0)
       b5p  = (-92097.0/339200.0)
       b6p  = (187.0/2100.0)
       b7p  = (1.0/40.0)
 
       x    = x0
       y    = y0
       h    = hmax
 
 
       for i in range(maxiter):
          # /* Compute the function values */
          K1 = fxy(x,       y)
          K2 = fxy(x+ c2*h, y+h*(a21*K1))
          K3 = fxy(x+ c3*h, y+h*(a31*K1+a32*K2))
          K4 = fxy(x+ c4*h, y+h*(a41*K1+a42*K2+a43*K3))
          K5 = fxy(x+ c5*h, y+h*(a51*K1+a52*K2+a53*K3+a54*K4))
          K6 = fxy(x+    h, y+h*(a61*K1+a62*K2+a63*K3+a64*K4+a65*K5))
          K7 = fxy(x+    h, y+h*(a71*K1+a72*K2+a73*K3+a74*K4+a75*K5+a76*K6))
 
          error = abs((b1-b1p)*K1+(b3-b3p)*K3+(b4-b4p)*K4+(b5-b5p)*K5+
                       (b6-b6p)*K6+(b7-b7p)*K7)
 
          # error control
          delta = 0.84 * pow(tol / error, (1.0/5.0))
          if (error < tol) :
             x = x + h
             y = y + h * (b1*K1+b3*K3+b4*K4+b5*K5+b6*K6)
 
 
          if (delta <= 0.1) :
             h = h * 0.1
          elif (delta >= 4.0 ) :
             h = h * 4.0
          else :
             h = delta * h
 
 
          if (h > hmax) :
             h = hmax
 
 
          if (x >= x1) :
             flag = 0
             break
 
          elif (x + h > x1) :
             h    = x1 - x
 
          elif (h < hmin) :
             flag = 1
             break
 
 
 
       maxiter = maxiter - i
       if (i <= 0) :
           flag = 2
 
       return (y,  flag,  maxiter)
 
 
if __name__ == "__main__":
    def fxy(x, y):
          return  3.0*y/x + x*x*x + x
    x0 = 1
    y0 = 3.0
    x1 = 2.0
    tol = 1.0e-5
    hmax = 1.0
    hmin = 0.01
    maxiter = 1000
    print(odedopri(fxy,  x0,  y0,  x1,  tol,  hmax,  hmin,  maxiter))