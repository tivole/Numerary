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

<b><i>Definition:</i></b> Let <b>F</b> be a real function from ![D⊂R](img/D_subset_Rn.gif) n to ![R^n](img/Rn.gif). If <b>F</b>(<b>p</b>) = <b>p</b>, for some ![p∈D](img/p_in_D.gif), then p is said to be a fixed point of <b>F</b>.

# Convergence

One of the things we will discuss is the convergence of each of the numerical
methods.

<b><i>Definition:</i></b> We say that a sequence <i>converges</i> if it has a limit.

<b><i>Definition:</i></b> Let ![pn](img/p_n.gif) be a sequence that converges to ![p](img/p.gif), where pn 6= p. If constants
λ, α > 0 exist such that

<p align="center">
    <img src="img/limit_1.png">
</p>

Then it is said that pn converges to p of order α with a constant λ.

<br />

There are three different orders of convergences.

<b><i>Definition:</i></b> A sequence ![pn](img/p_n.gif) is said to be linearly convergent if ![pn](img/p_n.gif) converges to ![p](img/p.gif) with order α = 1, for a constant λ < 1 such that

<p align="center">
    <img src="img/limit_1.png">
</p>

<b><i>Definition:</i></b> A sequence ![pn](img/p_n.gif) is said to be quadratically convergent if ![pn](img/p_n.gif) converges to ![p](img/p.gif) with order α = 2 such that

<p align="center">
    <img src="img/limit_1.png">
</p>

<b><i>Definition:</i></b> A sequence ![pn](img/p_n.gif) is said to be superlinearly convergent if

<p align="center">
    <img src="img/limit_2.png">
</p>

<b><i>Remark:</i></b> The value of α measures how fast a sequence converges. Thus the higher the value of α is, the more rapid the convergence of the sequence is. In the case of numerical methods, the sequence of approximate solutions is converging to the root. If the convergence of an iterative method is more rapid, then a solution may be reached in less interations in comparison to another method with a slower convergence.