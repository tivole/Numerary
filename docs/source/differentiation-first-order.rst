Numerical differentiation. Calculation of the first derivative.
===============================================================

Definition
----------

By definition, the first derivative of a smooth function :math:`f(x)` at a point x is calculated as

.. math::
    :nowrap:

    \begin{equation}
        f^{\prime}(x)=\lim _{h \rightarrow 0} \frac{f(x+h)-f(x)}{h}.
    \end{equation}

When calculating the first derivative of the function :math:`f(x)` on a computer, we replace the infinitesimal :math:`h \rightarrow \infty` with a small but finite value :math:`h`:

.. math::
    :nowrap:

    \begin{equation}
        f^{\prime}(x)=\frac{f(x+h)-f(x)}{h}+\mathrm{O}(h),
    \end{equation}

where :math:`\mathrm{O}(h)` is the derivative calculation error, which naturally depends on :math:`h`. Previous formula is called a difference scheme for calculating the first derivative (more precisely, a right difference scheme or just a right difference). Similarly, maybe the left-hand difference scheme is written.

How to determine :math:`\mathrm{O}(h)`? Expand the function :math:`f(x)` in a Taylor series at the point :math:`x + h`:

.. math::
    :nowrap:

    \begin{equation}
        f(x+h)=f(x)+h f^{\prime}(x)+\frac{h^{2}}{2} f^{\prime \prime}(x)+\frac{h^{3}}{6} f^{\prime \prime \prime}(x)+\ldots,
    \end{equation}

whence it follows that in the first order of the expansion

.. math::
    :nowrap:

    \begin{equation}
        \mathrm{O}(h)=-\frac{h}{2} f^{\prime \prime}(x)+\ldots.
    \end{equation}

By choosing a very small :math:`h`, the round-off errors in computing on a computer can be comparable to or greater than :math:`h`. Therefore, we are interested in an algorithm that gives lower error value for the same value of :math:`h`.

Such an improved algorithm can be easily obtained by expanding the function :math:`f(x)` into a Taylor series at the points :math:`x + h` and :math:`x - h`, then subtracting one result from the other, which gives

.. math::
    :nowrap:

    \begin{equation}
        f^{\prime}(x)=\frac{f(x+h)-f(x-h)}{2 h}+\mathrm{O}\left(h^{2}\right),
    \end{equation}

where the error in calculating the first derivative

.. math::
    :nowrap:

    \begin{align*}
        \mathrm{O}\left(h^{2}\right)=-\frac{h^{2}}{6} f^{\prime \prime \prime}(x)+\ldots.
    \end{align*}

This is the central difference scheme (central difference).

In principle, it is possible to follow the path of improving the accuracy of the method for calculating the first derivative and further. For example, considering the expansion of the function :math:`f(x)` in a Taylor series at the points :math:`x + h`, :math:`x + 2h`, :math:`x - h`, and :math:`x - 2h`, one can obtain a four-point scheme
etc.
