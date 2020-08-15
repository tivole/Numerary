Newton's Method
===============

Overview
--------

**Newton’s method** is one of the most popular numerical methods, and is even referred by *Burden* and *Faires* as the most powerful method that is used to solve for the equation :math:`f(x) = 0`. This method originates from the *Taylor’s series* expansion of the function :math:`f(x)` about the point :math:`x1`:

.. math::
    :nowrap:

    \begin{equation}
        f(x)=f\left(x_{1}\right)+\left(x-x_{1}\right) f^{\prime}\left(x_{1}\right)+\frac{1}{2 !}\left(x-x_{1}\right)^{2} f^{\prime \prime}\left(x_{1}\right)+\cdots
    \end{equation}

where :math:`f`, and its first and second order derivatives, :math:`f'` and :math:`f''` are calculated at :math:`x_1`. If we take the first two terms of the Taylor’s series expansion we have:

.. math::
    :nowrap:

    \begin{equation}
        f(x) \approx f\left(x_{1}\right)+\left(x-x_{1}\right) f^{\prime}\left(x_{1}\right).
    \end{equation}

We then set previous expression to zero (i.e :math:`f(x) = 0` ) to find the root of the equation which gives us:

.. math::
    :nowrap:

    \begin{equation}
        f\left(x_{1}\right)+\left(x-x_{1}\right) f^{\prime}\left(x_{1}\right)=0.
    \end{equation}

Rearranging the previous expression we obtain the next approximation to the root, giving us:

.. math::
    :nowrap:

    \begin{equation}
        x=x_{2}=x_{1}-\frac{f\left(x_{1}\right)}{f^{\prime}\left(x_{1}\right)}
    \end{equation}

Thus generalizing previous expression we obtain Newton’s iterative method:


.. math::
    :nowrap:

    \begin{equation}
        x_{i}=x_{i-1}-\frac{f\left(x_{i-1}\right)}{f^{\prime}\left(x_{i-1}\right)}, i \in \mathbb{N}
    \end{equation}



where :math:`x_{i} \rightarrow \bar{x}` (as :math:`i \rightarrow \infty`), and :math:`x` is the approximation to a root of the function :math:`f(x)`.

**Note:** As the iterations begin to have the same repeated values i.e. as :math:`x_i = x_{i+1} = \bar{x}` this is an indication that :math:`f(x)` converges to :math:`\bar{x}`. Thus :math:`x_i` is the root of the function :math:`f(x)`.



