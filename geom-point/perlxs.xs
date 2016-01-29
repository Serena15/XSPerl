#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include "const-c.inc"

typedef struct { double x, y; } GEOM_POINT;
typedef struct { double x, y, r; } CIRCLE;
typedef struct { double x, y, z; } GEOM_POINT_3D;

MODULE = Local::perlxs                PACKAGE = Local::perlxs                

INCLUDE: const-xs.inc

#include <math.h>
#include <stdio.h>

PROTOTYPES: DISABLE

double distance_point(x1,y1,x2,y2)
    double x1
    double y1
    double x2
    double y2

    CODE:
    double ret;
    ret = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    RETVAL = ret;

    OUTPUT:
    RETVAL

void distance_ext_point(x1,y1,x2,y2)
    double x1
    double y1
    double x2
    double y2

    PPCODE:
    double dx = fabs(x1-x2);
    double dy = fabs(y1-y2);
    double dist = sqrt( pow(dx, 2) + pow(dy, 2) );

    PUSHs(sv_2mortal(newSVnv(dist)));
    PUSHs(sv_2mortal(newSVnv(dx)));
    PUSHs(sv_2mortal(newSVnv(dy)));

double distance_call_point()
    PPCODE:
    int count;
    double x1, y1, x2, y2;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    PUTBACK;
    count = call_pv("Local::perlxs::get_points", G_ARRAY|G_NOARGS);

    SPAGAIN;
    if (count != 4) croak("call get_points trouble\n");
    x1 = POPn;
    y1 = POPn;
    x2 = POPn;
    y2 = POPn;
    double dist = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    FREETMPS;
    LEAVE;
    PUSHs(sv_2mortal(newSVnv(dist)));

double distance_call_arg_point()
    PPCODE:
    int count;
    double x1, y1, x2, y2;

    ENTER;
    SAVETMPS;

    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv(1)));
    PUTBACK;
    count = call_pv("Local::perlxs::get_points", G_ARRAY);
    SPAGAIN;
    if (count != 2) croak("call get_points trouble\n");
    x1 = POPn;
    y1 = POPn;

    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv(2)));
    PUTBACK;
    count = call_pv("Local::perlxs::get_points", G_ARRAY);
    SPAGAIN;
    if (count != 2) croak("call get_points trouble\n");
    x2 = POPn;
    y2 = POPn;

    double dist = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    FREETMPS;
    LEAVE;
    PUSHs(sv_2mortal(newSVnv(dist)));

double distance_pointobj(r_point1, r_point2)
    SV *r_point1
    SV *r_point2
    PPCODE:
    double x1,y1,x2,y2;
    SV **_x1, **_y1, **_x2, **_y2, *_point1, *_point2;
    HV *point1, *point2;
    if(!(SvOK(r_point1) && SvROK(r_point1) && SvOK(r_point2) && SvROK(r_point2))){
        croak("Point must be a hashref");
    }
    _point1 = SvRV(r_point1); _point2 = SvRV(r_point2);
    if( SvTYPE(_point1) != SVt_PVHV || SvTYPE(_point2) != SVt_PVHV){
        croak("Point must be a hashref");
    }
    point1 = (HV*)_point1; point2 = (HV*)_point2;
    if(!(hv_exists(point1, "x", 1) && hv_exists(point2, "x", 1) && 
            hv_exists(point1, "y", 1) && hv_exists(point2, "y", 1))){
        croak("Point mush contain x and y keys");
    }
    _x1 = hv_fetch(point1, "x", 1, 0); _y1 = hv_fetch(point1, "y", 1, 0);
    _x2 = hv_fetch(point2, "x", 1, 0); _y2 = hv_fetch(point2, "y", 1, 0);
    if( !(_x1 && _x2 && _y1 && _y2)){ croak("Non allow NULL in x and y coords"); }
    x1 = SvNV(*_x1); x2 = SvNV(*_x2);
    y1 = SvNV(*_y1); y2 = SvNV(*_y2);
    PUSHs(sv_2mortal(newSVnv(sqrt( pow(x1-x2,2) + pow(y1-y2,2)))));


double distance_pointstruct(point1, point2)
    GEOM_POINT *point1
    GEOM_POINT *point2
    CODE:
    double ret;
    ret = sqrt( pow(point1->x-point2->x,2) + pow(point1->y-point2->y,2));
    free(point1);
    free(point2);
    RETVAL = ret;
    OUTPUT:
    RETVAL

double distance3d_pointstruct(point1, point2)
    GEOM_POINT_3D *point1
    GEOM_POINT_3D *point2
    CODE:
    double ret;
    ret = sqrt( pow(point1->x-point2->x,2) + pow(point1->y-point2->y,2) + pow(point1->z-point2->z,2));
    free(point1);
    free(point2);
    RETVAL = ret;
    OUTPUT:
    RETVAL




double distance_call_point_2(function)
    char *function
    PPCODE:
    int count;
    double x1, y1, x2, y2;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    PUTBACK;
    count = call_pv(function, G_ARRAY|G_NOARGS);

    SPAGAIN;
    if (count != 4) croak("call get_points trouble\n");
    x1 = POPn;
    y1 = POPn;
    x2 = POPn;
    y2 = POPn;
    double dist = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    FREETMPS;
    LEAVE;
    PUSHs(sv_2mortal(newSVnv(dist)));


double distance_call_arg_point_2(function)
    char *function
    PPCODE:
    int count;
    double x1, y1, x2, y2;

    ENTER;
    SAVETMPS;

    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv(1)));
    PUTBACK;
    count = call_pv(function, G_ARRAY);
    SPAGAIN;
    if (count != 2) croak("call get_points trouble\n");
    x1 = POPn;
    y1 = POPn;

    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv(2)));
    PUTBACK;
    count = call_pv(function, G_ARRAY);
    SPAGAIN;
    if (count != 2) croak("call get_points trouble\n");
    x2 = POPn;
    y2 = POPn;

    double dist = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    FREETMPS;
    LEAVE;
    PUSHs(sv_2mortal(newSVnv(dist)));



double distance_circlestruct(point, circle)
    GEOM_POINT *point
    CIRCLE *circle
    CODE:
    double ret;
    ret = abs(sqrt( pow(point->x-circle->x,2) + pow(point->y-circle->y,2)) - circle->r);
    free(point);
    free(circle);
    RETVAL = ret;
    OUTPUT:
    RETVAL


SV * crosspoint_circlestruct(point, circle)
    GEOM_POINT *point
    CIRCLE *circle

    CODE:
    HV *rh = newHV();
    double distance;
    distance = sqrt( pow(point->x-circle->x,2) + pow(point->y-circle->y,2)) - circle->r;
    if (distance == 0) {
        hv_store(rh, "x", 1, newSViv(point->x), 0);
    	hv_store(rh, "y", 1, newSViv(point->y), 0);
    }
    else {
	double k;
	double x_our;
	double y_our;
	double x_our2;
	double y_our2;
	if (!(point->x-circle->x)) {
	   x_our = point->x;
	   y_our = circle->r + circle->y;
	   y_our2 = - circle->r + circle->y;
	   hv_store(rh, "x", 1, newSViv(x_our), 0);
	   if (abs(point->y - y_our2) < abs(point->y - y_our)) {
		hv_store(rh, "y", 1, newSViv(y_our2), 0);
	   }
	   else {
		hv_store(rh, "y", 1, newSViv(y_our), 0);
	   }
	}
	else if(!(point->y-circle->y)) {
	   y_our = point->y;
	   x_our = circle->r + circle->x;
	   x_our2 = - circle->r + circle->x;
	   hv_store(rh, "y", 1, newSViv(y_our), 0);
	   if (abs(point->x - x_our2) < abs(point->x - x_our)) {
		hv_store(rh, "x", 1, newSViv(x_our2), 0);
	   }
	   else {
		hv_store(rh, "x", 1, newSViv(x_our), 0);
	   }
	}
	else {
            k = (point->y-circle->y)/(point->x-circle->x);
	    double b = point->y - (point->x)*k;
            double diskr = pow(k*b-k*(circle->y)-circle->x,2) - (1 + k*k)*(pow(circle->x,2) + b*b + pow(circle->y,2) - 2*b*(circle->y) - pow(circle->r,2));
        if(diskr > 0) {
		x_our = (-k*b+k*(circle->y)+circle->x + sqrt(diskr))/(1 + k*k);
		y_our = k*x_our+b;
		x_our2 = (-k*b+k*(circle->y)+circle->x - sqrt(diskr))/(1 + k*k);
		y_our2 = k*x_our2+b;
		double dist = sqrt( pow(point->x-x_our, 2) + pow(point->y-y_our, 2) );	
		double dist2 = sqrt( pow(point->x-x_our2, 2) + pow(point->y-y_our2, 2) );
		if(distance < 0) {
	    		if (dist > dist2) {
	        		hv_store(rh, "x", 1, newSViv(x_our), 0);
    	        		hv_store(rh, "y", 1, newSViv(y_our), 0);
	    		}
	    		else {
				hv_store(rh, "x", 1, newSViv(x_our2), 0);
    	        		hv_store(rh, "y", 1, newSViv(y_our2), 0);
	    		}
		}
		else {
	   		if (dist < dist2) {
	        		hv_store(rh, "x", 1, newSViv(x_our), 0);
    	       			hv_store(rh, "y", 1, newSViv(y_our), 0);
	    		}
	    		else {
				hv_store(rh, "x", 1, newSViv(x_our2), 0);
    	        		hv_store(rh, "y", 1, newSViv(y_our2), 0);
	    		}	    
		}
	}
	else if (diskr == 0){
	    x_our = (-k*b+k*(circle->y)+circle->x + sqrt(diskr))/(1 + k*k);
	    y_our = k*x_our+b;
	    hv_store(rh, "x", 1, newSViv(x_our), 0);
    	    hv_store(rh, "y", 1, newSViv(y_our), 0);
	}
	else {
		printf("The solving is absent(D < 0)\n");
		hv_store(rh, "x", 1, newSViv(undef), 0);
    	    	hv_store(rh, "y", 1, newSViv(undef), 0);
	}
	}
    }
    
    free(point);
    free(circle);
    
    RETVAL = sv_2mortal((SV*)newRV_noinc((SV*)rh));
    OUTPUT:
    RETVAL


