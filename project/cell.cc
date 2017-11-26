#include "cell.h"


// Other Methods ------------------------





// Big 5 + ctor -------------------------

Cell::Cell(int r, int c)
: r{r}, c{c} {/* CTOR BODY */}


Cell::Cell(const Cell &other)
: /* Copy superclasses (i.e. Subject) */r{other.r}, c{other.c} {/* COPY CTOR BODY */}

Cell::Cell(Cell &&other)
: /* Copy superclasses (i.e. Subject) */r{other.r}, c{other.c} {/* COPY CTOR BODY */}

