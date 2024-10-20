# Charley a Genetic algorithm mesh network designer.

This repository contains the documentation for Charley (a genetic algorithm mesh network designer) and the source code
for the program.
The program was created as my final thesis project for my BSc in Computer Science at the University of Greenwich. Way
back in 1995.

I'm placing this on GitHub as a historical record and to avoid that the source code is lost to the great bit bucket in
the sky.

I studied for my Degree part-time while working as a (Medical laboratory scientific officer, Software Developer) at
Charring Cross Hospital.
As the degree was part-time (one day a week) the 3 year degree was spread over 6 years. Final "year" part-time students
were given 2 years
in which to complete their thesis. One year into working on a "programing language to simplify integrating laboratory
equipment"
(Unfortunately the source code to this endeavour is lost, but every developer of that era had to have created at least
one programing
language) We were set a two-day open book exam to design a network fitting a given a set of requirements. I wondered if
a
"Genetic Algorithm" GA could be applied to the problem and threw a program together to test the idea.
I designed the exam network by hand following the normal heuristic algorithms, and was able to confirmed that the GA
produced the same result.  
I handed in network that I had designed and included the results of the GA as an appendix.

I was so excited by the results that I immediately wanted to change my thesis to this idea. My mentor at the time (Sati
McKenzie) was
also very enthusiastic, although she did point out that I was being a "Right Charley" to do this as I was basically
throwing away a years
effort, and now had two years work to do in one year;

Well after many late nights and weekends (Sati added the extra complication of solving mesh networks with a defined
level of redundancy)
Charley was completed and submitted.

I received a first class honors degree for my efforts.

I also had the pleasure of presenting Charley at the 1995 IEEE GALESIA conference in Sheffield. Much later I found out
that the paper
had been referenced as prior art in a patent application.

I have included in this repository the original thesis, the abstract and the source code. The source code is written in
C and my intention
is to at least get it to compile and run on a modern system. I'm also toying with the idea of re-writing it in Golang. I
still think there
are some interesting ideas particularly around the DNA representation of the network (which might be directly applicable
to other problems
that can be represented as nodes in a mesh). Also, the network calculation code was interesting because it had calculate
the fitness function
for partial networks (a network that has no links is very cheap but pretty useless and that had to be reflected in the
function).

## Build and test

The code has been "updated" it has been provided with a CMakeLists.txt so the normal

At the moment the code probably does not build. I have

not tried to build it since 1995. However I have included the original makefile and all
the source code. No external libraries were used so it should be a fairly simple matter to get it to build. I will
update this section when I've
had a chance to try it.

## Contribute

I would be amazed if anyone was interested in contributing... but if anyone were to feel so inclined I'm open to pull
requests.


