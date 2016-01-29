/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of perlxs.xs. Do not edit this file, edit perlxs.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "perlxs.xs"
#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include "const-c.inc"

typedef struct { double x, y; } GEOM_POINT;
typedef struct { double x, y, r; } CIRCLE;
typedef struct { double x, y, z; } GEOM_POINT_3D;

#line 24 "perlxs.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 166 "perlxs.c"

/* INCLUDE:  Including 'const-xs.inc' from 'perlxs.xs' */


XS_EUPXS(XS_Local__perlxs_constant); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_constant)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 4 "./const-xs.inc"
#ifdef dXSTARG
	dXSTARG; /* Faster if we have it.  */
#else
	dTARGET;
#endif
	STRLEN		len;
        int		type;
	/* IV		iv;	Uncomment this if you need to return IVs */
	/* NV		nv;	Uncomment this if you need to return NVs */
	/* const char	*pv;	Uncomment this if you need to return PVs */
#line 191 "perlxs.c"
	SV *	sv = ST(0)
;
	const char *	s = SvPV(sv, len);
#line 18 "./const-xs.inc"
	type = constant(aTHX_ s, len);
      /* Return 1 or 2 items. First is error message, or undef if no error.
           Second, if present, is found value */
        switch (type) {
        case PERL_constant_NOTFOUND:
          sv =
	    sv_2mortal(newSVpvf("%s is not a valid Local::perlxs macro", s));
          PUSHs(sv);
          break;
        case PERL_constant_NOTDEF:
          sv = sv_2mortal(newSVpvf(
	    "Your vendor has not defined Local::perlxs macro %s, used",
				   s));
          PUSHs(sv);
          break;
	/* Uncomment this if you need to return IVs
        case PERL_constant_ISIV:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHi(iv);
          break; */
	/* Uncomment this if you need to return NOs
        case PERL_constant_ISNO:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHs(&PL_sv_no);
          break; */
	/* Uncomment this if you need to return NVs
        case PERL_constant_ISNV:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHn(nv);
          break; */
	/* Uncomment this if you need to return PVs
        case PERL_constant_ISPV:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHp(pv, strlen(pv));
          break; */
	/* Uncomment this if you need to return PVNs
        case PERL_constant_ISPVN:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHp(pv, iv);
          break; */
	/* Uncomment this if you need to return SVs
        case PERL_constant_ISSV:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHs(sv);
          break; */
	/* Uncomment this if you need to return UNDEFs
        case PERL_constant_ISUNDEF:
          break; */
	/* Uncomment this if you need to return UVs
        case PERL_constant_ISUV:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHu((UV)iv);
          break; */
	/* Uncomment this if you need to return YESs
        case PERL_constant_ISYES:
          EXTEND(SP, 1);
          PUSHs(&PL_sv_undef);
          PUSHs(&PL_sv_yes);
          break; */
        default:
          sv = sv_2mortal(newSVpvf(
	    "Unexpected return type %d while processing Local::perlxs macro %s, used",
               type, s));
          PUSHs(sv);
        }
#line 268 "perlxs.c"
	PUTBACK;
	return;
    }
}


/* INCLUDE: Returning to 'perlxs.xs' from 'const-xs.inc' */

#include <math.h>
#include <stdio.h>

XS_EUPXS(XS_Local__perlxs_distance_point); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_point)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "x1, y1, x2, y2");
    {
	double	x1 = (double)SvNV(ST(0))
;
	double	y1 = (double)SvNV(ST(1))
;
	double	x2 = (double)SvNV(ST(2))
;
	double	y2 = (double)SvNV(ST(3))
;
	double	RETVAL;
	dXSTARG;
#line 30 "perlxs.xs"
    double ret;
    ret = sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
    RETVAL = ret;

#line 302 "perlxs.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Local__perlxs_distance_ext_point); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_ext_point)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "x1, y1, x2, y2");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	double	x1 = (double)SvNV(ST(0))
;
	double	y1 = (double)SvNV(ST(1))
;
	double	x2 = (double)SvNV(ST(2))
;
	double	y2 = (double)SvNV(ST(3))
;
#line 44 "perlxs.xs"
    double dx = fabs(x1-x2);
    double dy = fabs(y1-y2);
    double dist = sqrt( pow(dx, 2) + pow(dy, 2) );

    PUSHs(sv_2mortal(newSVnv(dist)));
    PUSHs(sv_2mortal(newSVnv(dx)));
    PUSHs(sv_2mortal(newSVnv(dy)));
#line 334 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_call_point); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_call_point)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	double	RETVAL;
	dXSTARG;
#line 54 "perlxs.xs"
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
#line 371 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_call_arg_point); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_call_arg_point)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	double	RETVAL;
	dXSTARG;
#line 75 "perlxs.xs"
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
#line 418 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_pointobj); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_pointobj)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "r_point1, r_point2");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	r_point1 = ST(0)
;
	SV *	r_point2 = ST(1)
;
	double	RETVAL;
	dXSTARG;
#line 108 "perlxs.xs"
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
#line 462 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_pointstruct); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_pointstruct)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "point1, point2");
    {
	GEOM_POINT *	point1;
	GEOM_POINT *	point2;
	double	RETVAL;
	dXSTARG;

	{
	double typemap_x, typemap_y;
	if(!(SvOK(ST(0)) && SvROK(ST(0)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(0));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	if( !(typemap__x && typemap__y) ){ croak("Non allow NULL in x and y coords");}
	typemap_x = SvNV(*typemap__x); typemap_y = SvNV(*typemap__y);
	GEOM_POINT * pt = malloc(sizeof(GEOM_POINT));
	pt->x = typemap_x; pt->y = typemap_y;
	point1 = (GEOM_POINT *)pt;
	}
;

	{
	double typemap_x, typemap_y;
	if(!(SvOK(ST(1)) && SvROK(ST(1)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(1));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	if( !(typemap__x && typemap__y) ){ croak("Non allow NULL in x and y coords");}
	typemap_x = SvNV(*typemap__x); typemap_y = SvNV(*typemap__y);
	GEOM_POINT * pt = malloc(sizeof(GEOM_POINT));
	pt->x = typemap_x; pt->y = typemap_y;
	point2 = (GEOM_POINT *)pt;
	}
;
#line 135 "perlxs.xs"
    double ret;
    ret = sqrt( pow(point1->x-point2->x,2) + pow(point1->y-point2->y,2));
    free(point1);
    free(point2);
    RETVAL = ret;
#line 524 "perlxs.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Local__perlxs_distance3d_pointstruct); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance3d_pointstruct)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "point1, point2");
    {
	GEOM_POINT_3D *	point1;
	GEOM_POINT_3D *	point2;
	double	RETVAL;
	dXSTARG;

	{
	double typemap_x, typemap_y, typemap_z;
	if(!(SvOK(ST(0)) && SvROK(ST(0)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(0));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1) && hv_exists(typemap_point, "z", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	SV **typemap__z = hv_fetch(typemap_point, "z", 1, 0);
	if( !(typemap__x && typemap__y && typemap__z)){ croak("Non allow NULL in x or y or z coords");}
	typemap_x = SvNV(*typemap__x);
	typemap_y = SvNV(*typemap__y);
	typemap_z = SvNV(*typemap__z);
	GEOM_POINT_3D * pt = malloc(sizeof(GEOM_POINT_3D));
	pt->x = typemap_x; pt->y = typemap_y; pt->z = typemap_z;
	point1 = (GEOM_POINT_3D *)pt;
	}
;

	{
	double typemap_x, typemap_y, typemap_z;
	if(!(SvOK(ST(1)) && SvROK(ST(1)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(1));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1) && hv_exists(typemap_point, "z", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	SV **typemap__z = hv_fetch(typemap_point, "z", 1, 0);
	if( !(typemap__x && typemap__y && typemap__z)){ croak("Non allow NULL in x or y or z coords");}
	typemap_x = SvNV(*typemap__x);
	typemap_y = SvNV(*typemap__y);
	typemap_z = SvNV(*typemap__z);
	GEOM_POINT_3D * pt = malloc(sizeof(GEOM_POINT_3D));
	pt->x = typemap_x; pt->y = typemap_y; pt->z = typemap_z;
	point2 = (GEOM_POINT_3D *)pt;
	}
;
#line 147 "perlxs.xs"
    double ret;
    ret = sqrt( pow(point1->x-point2->x,2) + pow(point1->y-point2->y,2) + pow(point1->z-point2->z,2));
    free(point1);
    free(point2);
    RETVAL = ret;
#line 592 "perlxs.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Local__perlxs_distance_call_point_2); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_call_point_2)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "function");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	char *	function = (char *)SvPV_nolen(ST(0))
;
	double	RETVAL;
	dXSTARG;
#line 161 "perlxs.xs"
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
#line 631 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_call_arg_point_2); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_call_arg_point_2)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "function");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	char *	function = (char *)SvPV_nolen(ST(0))
;
	double	RETVAL;
	dXSTARG;
#line 184 "perlxs.xs"
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
#line 680 "perlxs.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Local__perlxs_distance_circlestruct); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_distance_circlestruct)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "point, circle");
    {
	GEOM_POINT *	point;
	CIRCLE *	circle;
	double	RETVAL;
	dXSTARG;

	{
	double typemap_x, typemap_y;
	if(!(SvOK(ST(0)) && SvROK(ST(0)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(0));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	if( !(typemap__x && typemap__y) ){ croak("Non allow NULL in x and y coords");}
	typemap_x = SvNV(*typemap__x); typemap_y = SvNV(*typemap__y);
	GEOM_POINT * pt = malloc(sizeof(GEOM_POINT));
	pt->x = typemap_x; pt->y = typemap_y;
	point = (GEOM_POINT *)pt;
	}
;

	{
	double typemap_x, typemap_y, typemap_r;
	if(!(SvOK(ST(1)) && SvROK(ST(1)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(1));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1) && hv_exists(typemap_point, "r", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	SV **typemap__r = hv_fetch(typemap_point, "r", 1, 0);
	if( !(typemap__x && typemap__y && typemap__r)){ croak("Non allow NULL in x or y or r");}
	typemap_x = SvNV(*typemap__x);
	typemap_y = SvNV(*typemap__y);
	typemap_r = SvNV(*typemap__r);
	CIRCLE * pt = malloc(sizeof(CIRCLE));
	pt->x = typemap_x; pt->y = typemap_y; pt->r = typemap_r;
	circle = (CIRCLE *)pt;
	}
;
#line 219 "perlxs.xs"
    double ret;
    ret = abs(sqrt( pow(point->x-circle->x,2) + pow(point->y-circle->y,2)) - circle->r);
    free(point);
    free(circle);
    RETVAL = ret;
#line 745 "perlxs.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Local__perlxs_crosspoint_circlestruct); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Local__perlxs_crosspoint_circlestruct)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "point, circle");
    {
	GEOM_POINT *	point;
	CIRCLE *	circle;
	SV *	RETVAL;

	{
	double typemap_x, typemap_y;
	if(!(SvOK(ST(0)) && SvROK(ST(0)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(0));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	if( !(typemap__x && typemap__y) ){ croak("Non allow NULL in x and y coords");}
	typemap_x = SvNV(*typemap__x); typemap_y = SvNV(*typemap__y);
	GEOM_POINT * pt = malloc(sizeof(GEOM_POINT));
	pt->x = typemap_x; pt->y = typemap_y;
	point = (GEOM_POINT *)pt;
	}
;

	{
	double typemap_x, typemap_y, typemap_r;
	if(!(SvOK(ST(1)) && SvROK(ST(1)))){ croak("Point must be a hashref"); }
	SV *typemap__point = SvRV(ST(1));
	if( SvTYPE(typemap__point) != SVt_PVHV ){croak("Point must be a hashref");}
	HV *typemap_point = (HV*)typemap__point;
	if(!(hv_exists(typemap_point, "x", 1) && hv_exists(typemap_point, "y", 1) && hv_exists(typemap_point, "r", 1))){
		croak("Point mush contain x and y keys");
	}
	SV **typemap__x = hv_fetch(typemap_point, "x", 1, 0);
	SV **typemap__y = hv_fetch(typemap_point, "y", 1, 0);
	SV **typemap__r = hv_fetch(typemap_point, "r", 1, 0);
	if( !(typemap__x && typemap__y && typemap__r)){ croak("Non allow NULL in x or y or r");}
	typemap_x = SvNV(*typemap__x);
	typemap_y = SvNV(*typemap__y);
	typemap_r = SvNV(*typemap__r);
	CIRCLE * pt = malloc(sizeof(CIRCLE));
	pt->x = typemap_x; pt->y = typemap_y; pt->r = typemap_r;
	circle = (CIRCLE *)pt;
	}
;
#line 233 "perlxs.xs"
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
        if(diskr) {
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
	else {
	    x_our = (-k*b+k*(circle->y)+circle->x + sqrt(diskr))/(1 + k*k);
	    y_our = k*x_our+b;
	    hv_store(rh, "x", 1, newSViv(x_our), 0);
    	    hv_store(rh, "y", 1, newSViv(y_our), 0);
	}
	}
    }

    free(point);
    free(circle);

    RETVAL = sv_2mortal((SV*)newRV_noinc((SV*)rh));
#line 886 "perlxs.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Local__perlxs); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Local__perlxs)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("Local::perlxs::constant", XS_Local__perlxs_constant, file);
        newXS("Local::perlxs::distance_point", XS_Local__perlxs_distance_point, file);
        newXS("Local::perlxs::distance_ext_point", XS_Local__perlxs_distance_ext_point, file);
        newXS("Local::perlxs::distance_call_point", XS_Local__perlxs_distance_call_point, file);
        newXS("Local::perlxs::distance_call_arg_point", XS_Local__perlxs_distance_call_arg_point, file);
        newXS("Local::perlxs::distance_pointobj", XS_Local__perlxs_distance_pointobj, file);
        newXS("Local::perlxs::distance_pointstruct", XS_Local__perlxs_distance_pointstruct, file);
        newXS("Local::perlxs::distance3d_pointstruct", XS_Local__perlxs_distance3d_pointstruct, file);
        newXS("Local::perlxs::distance_call_point_2", XS_Local__perlxs_distance_call_point_2, file);
        newXS("Local::perlxs::distance_call_arg_point_2", XS_Local__perlxs_distance_call_arg_point_2, file);
        newXS("Local::perlxs::distance_circlestruct", XS_Local__perlxs_distance_circlestruct, file);
        newXS("Local::perlxs::crosspoint_circlestruct", XS_Local__perlxs_crosspoint_circlestruct, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

