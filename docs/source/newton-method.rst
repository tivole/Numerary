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


The Method
----------

Step 1:
^^^^^^^

Let :math:`\mathbf{x}^{(0)}=\left(x_{1}^{(0)}, x_{2}^{(0)}, \ldots, x_{n}^{(0)}\right)` be a given initial vector.

Step 2:
^^^^^^^

Calculate :math:`J\left(\mathbf{x}^{(0)}\right)` and :math:`\mathbf{F}\left(\mathbf{x}^{(0)}\right)`.

Step 3:
^^^^^^^

We now have to calculate the vector :math:`\mathbf{y}^{(0)}`, where

.. math::
    :nowrap:

    \begin{equation}
        \mathbf{y}=
        \left[
            \begin{array}{c}
                y_{1} \\
                y_{2} \\
                \vdots \\
                y_{n}
            \end{array}
        \right]
    \end{equation}

In order to find :math:`\mathbf{y}^{(0)}`, we solve the linear system :math:`J\left(\mathbf{x}^{(0)}\right) \mathbf{y}^{(0)}=-\mathbf{F}\left(\mathbf{x}^{(0)}\right)`, using Gaussian Elimination.

**Note:** Rearranging the system in *Step 3*, we get that :math:`\mathbf{y}^{(0)}=-J\left(\mathbf{x}^{(0)}\right)^{-1} \mathbf{F}\left(\mathbf{x}^{(0)}\right)`. The significance of this is that, since :math:`\mathbf{y}^{(0)}=-J\left(\mathbf{x}^{(0)}\right)^{-1} \mathbf{F}\left(\mathbf{x}^{(0)}\right)`, we can replace :math:`-J\left(\mathbf{x}^{(0)}\right)^{-1} \mathbf{F}\left(\mathbf{x}^{(0)}\right)` in our iterative formula with :math:`\mathbf{y}^{(0)}`. This result will yield that

.. math::
    :nowrap:

    \begin{equation}
        \mathbf{x}^{(k)}=\mathbf{x}^{(k-1)}-J\left(\mathbf{x}^{(k-1)}\right)^{-1} \mathbf{F}\left(\mathbf{x}^{(k-1)}\right)=\mathbf{x}^{(k-1)}-\mathbf{y}^{(k-1)}
    \end{equation}


Step 4:
^^^^^^^

Once :math:`\mathbf{y}^{(0)}` is found, we can now proceed to finish the first iteration by solving for :math:`\mathbf{x}^{(1)}`. Thus using the result from *Step 3*, we have that

.. math::
    :nowrap:

    \begin{equation}
        \mathbf{x}^{(1)}=\mathbf{x}^{(0)}+\mathbf{y}^{(0)}=
        \left[\begin{array}{c}
            x_{1}^{(0)} \\
            x_{2}^{(0)} \\
            \vdots \\
            x_{n}^{(0)}
        \end{array}\right]
        +
        \left[\begin{array}{c}
            y_{1}^{(0)} \\
            y_{2}^{(0)} \\
            \vdots \\
            y_{n}^{(0)}
        \end{array}\right]
    \end{equation}


Step 5:
^^^^^^^

Once we have calculated :math:`\mathbf{x}^{(1)}`, we repeat the process again, until :math:`\mathbf{x}^{(k)}` converges to :math:`\bar{x}`. This indicates we have reached the solution to :math:`\mathbf{F}(\mathbf{x})=\mathbf{0}`, where :math:`\bar{x}` is the solution to the system.

**Note:** When a set of vectors converges, the norm :math:`\left\|\mathbf{x}^{(k)}-\mathbf{x}^{(k-1)}\right\|=0`. This means that

.. math::
    :nowrap:

    \begin{equation}
        \left\|\mathbf{x}^{(k)}-\mathbf{x}^{(k-1)}\right\|=\sqrt{\left(x_{1}^{(k)}-x_{1}^{(k-1)}\right)^{2}+\cdots+\left(x_{n}^{(k)}-x_{n}^{(k-1)}\right)^{2}}=0
    \end{equation}


