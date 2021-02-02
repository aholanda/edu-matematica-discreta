-------------------------------- MODULE MDC --------------------------------
EXTENDS Integers
CONSTANTS M,N
VARIABLES x,y
PositiveInteger == CHOOSE i : i \in Nat /\ i # 0
-----------------------------------------------------------------------------
TypeInvariant ==    x \in PositiveInteger 
                 /\ y \in PositiveInteger

(* Estado inicial *)
MDCInit == (x=M) /\ (y=N)

(* Proximo estado da computacao *)
MDCNext ==   ((x<y) /\ (x'=x) /\ (y'=y-x))
           \/  ((y<x) /\ (y'=y) /\ (x'=x-y))

Spec == MDCInit /\ [][MDCNext]_<<x,y>>
-----------------------------------------------------------------------------
THEOREM Spec => TypeInvariant
=============================================================================
\* Modification History
\* Last modified Mon Oct 22 22:02:21 BRST 2012 by ajh
\* Created Mon Oct 22 20:30:22 BRST 2012 by ajh
