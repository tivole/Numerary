Dormand-Prince Method
=====================

The one step calculation in the Dormand-Prince method is done as the following.

.. math::
    :nowrap:

    \begin{equation}
        \begin{aligned}
            k_{1} &=h f\left(t_{k}, y_{k}\right), \\
            k_{2} &=h f\left(t_{k}+\frac{1}{5} h, y_{k}+\frac{1}{5} k_{1}\right), \\
            k_{3} &=h f\left(t_{k}+\frac{3}{10} h, y_{k}+\frac{3}{40} k_{1}+\frac{9}{40} k_{2}\right), \\
            k_{4} &=h f\left(t_{k}+\frac{4}{5} h, y_{k}+\frac{44}{45} k_{1}-\frac{56}{15} k_{2}+\frac{32}{9} k_{3}\right), \\
            k_{5} &=h f\left(t_{k}+\frac{8}{9} h, y_{k}+\frac{19372}{6561} k_{1}-\frac{25360}{2187} k_{2}+\frac{64448}{6561} k_{3}-\frac{212}{729} k_{4}\right), \\
            k_{6} &=h f\left(t_{k}+h, y_{k}+\frac{9017}{3168} k_{1}-\frac{355}{33} k_{2}-\frac{46732}{5247} k_{3}+\frac{49}{176} k_{4}-\frac{5103}{18656} k_{5}\right), \\
            k_{7} &=h f\left(t_{k}+h, y_{k}+\frac{35}{384} k_{1}+\frac{500}{1113} k_{3}+\frac{125}{192} k_{4}-\frac{2187}{6784} k_{5}+\frac{11}{84} k_{6}\right).
        \end{aligned}
    \end{equation}

Then the next step value :math:`y_{k+1}` is calculated as

.. math::
    :nowrap:

    \begin{equation}
        y_{k+1}=y_{k}+\frac{35}{384} k_{1}+\frac{500}{1113} k_{3}+\frac{125}{192} k_{4}-\frac{2187}{6784} k_{5}+\frac{11}{84} k_{6}.
    \end{equation}

This is a calculation by Runge-Kutta method of order 4. We have to be aware that we do not use :math:`k_2`, though it is used to calculate :math:`k_3` and so on.

Next, we will calculate the next step value :math:`z_{k+1}` by Runge-Kutta method of order 5 as

.. math::
    :nowrap:

    \begin{equation}
        z_{k+1}=y_{k}+\frac{5179}{57600} k_{1}+\frac{7571}{16695} k_{3}+\frac{393}{640} k_{4}-\frac{92097}{339200} k_{5}+\frac{187}{2100} k_{6}+\frac{1}{40} k_{7}
    \end{equation}

We calculate the difference of the two next values :math:`\left|z_{k+1}-y_{k+1}\right|`.

.. math::
    :nowrap:
    
    \begin{equation}
        \left|z_{k+1}-y_{k+1}\right|=\left|\frac{71}{57600} k_{1}-\frac{71}{16695} k_{3}+\frac{71}{1920} k_{4}-\frac{17253}{339200} k_{5}+\frac{22}{525} k_{6}-\frac{1}{40} k_{7}\right|
    \end{equation}

This is considered as the error in :math:`y_{k+1}`. We calculate the optimal time interval :math:`h_{opt}` as,

.. math::
    :nowrap:

    \begin{equation}
        s =\left(\frac{\varepsilon h}{2\left|z_{k+1}-y_{k+1}\right|}\right)^{\frac{1}{5}}, \\
        h_{o p t} =s h,
    \end{equation}

where :math:`h` in the right side is the old time interval. In practical programming, this new :math:`h_{opt}` will be used in the next step of the calculation, though the author thinks it should be also used in the present calculation when it is very small, half or smaller for example.
