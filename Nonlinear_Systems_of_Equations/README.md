# A Nonlinear Systems of Equations

<b><i>Definition:</i></b> A function ![f:R^n->R](img/f:R^n->R.gif) is defined as being <i>nonlinear</i> when it does not satisfy the <i>superposition principle</i> that is

<p align="center">
    <img src="img/nonlinear_def.svg">
</p>

Now that we know what the term nonlinear refers to we can define a <i>system of nonlinear equations</i>.

<br />

<b><i>Definition:</i></b> A <i>system of nonlinear equations</i> is a set of equations as the following:

<p align="center">
    <img src="img/system_of_nonlinear_equations.png">
</p>

where ![(x1, x2, ..., xn) ∈ R^n](img/x_in_Rn.gif) and each ![f_i](img/f_i.gif) is a nonlinear real function, ![i=1,2,...,n](img/i=1,2,n.gif).

<br />

<b><i>Definition:</i></b> A solution of a system of equations ![f1,f2,...,fn](img/f1_fn.gif) in n variables is a point ![(a1, ..., an) ∈ R^n](img/a_in_Rn.gif) such that ![f1(a1,...,an)=···=fn(a1,...,an)=0](img/f_1=f_n=0.gif).

<br />

Because systems of nonlinear equations can not be solved as nicely as linear systems,
we use procedures called iterative methods.

<b><i>Definition:</i></b> An <i>iterative method</i> is a procedure that is repeated over and over again, to find the root of an equation or find the solution of a system of equations.