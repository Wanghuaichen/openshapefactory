#pragma once

#ifndef HSFSCRIPTINGINTERFACE_H
#define HSFSCRIPTINGINTERFACE_H


#include <QScriptable>
#include <QObject>
#include <QScriptValue>
#include <QScriptContext>
#include <QScriptEngine>

#include "shapefactory.h" // HybridShapeFactory factory middleware for OpenCascade
#include "ui.h"  // user interface singleton 
#include "User_AIS.hxx" //ais object for displaying TopoDS_Shape
#include "AIS_Gauss.hxx" // ais object for displaying TopoDS_Shape with curvature analysis

 Q_DECLARE_METATYPE(shapefactory)
 Q_DECLARE_METATYPE(gp_Pnt)
 Q_DECLARE_METATYPE(gp_Vec)
 Q_DECLARE_METATYPE(TopoDS_Shape)
 Q_DECLARE_METATYPE(QList<TopoDS_Shape>)


 class HsfScriptingInterface: public QObject, protected QScriptable
 {
     Q_OBJECT
 public:
 HsfScriptingInterface();
 ~HsfScriptingInterface();

 private:

	Handle_AIS_InteractiveContext ic ;
	int viscount;
	int gaussviscount;
	TopoDS_Compound folder;
	TopoDS_Compound gaussfolder;
	BRep_Builder B;
	Handle_User_AIS aisp;
	Handle(AIS_Gauss) mygauss;
	bool showgaussedges;




 public slots:

     

	//// utility functions
      QScriptValue vis();
	  QScriptValue viscurvature();
	  QScriptValue initpart();
	  QScriptValue endpart();
 //    
	  //listopertation
	  QScriptValue makeshapelist();
	  QScriptValue addshapetolist();

 //     //object factory

	//  //points
		QScriptValue makepoint();
	//  QScriptValue makepointoncurve();
	//  QScriptValue makeprojectpointonsurface();
	//  QScriptValue makeprojectpointoncurve();
	//  QScriptValue makecenterofgravitypoint();
	//  QScriptValue makepointbetween();
	//  QScriptValue makeuvpoint();
	//  QScriptValue makeintersectionpoint();
	//  QScriptValue makeintersectionpointmulti();
	//  
	//  //curves
	    QScriptValue makeline();
	//  QScriptValue makelinenormal();
	//  QScriptValue makebspline();
	//  QScriptValue makeinterpolatespline();
	//  QScriptValue makebeziercurve();
	//  QScriptValue makecorner();
	    QScriptValue makecircle();
	//  QScriptValue makeellipse();
	//  QScriptValue makearc();
	//  QScriptValue makearcofellipse();
	//  QScriptValue makehyberbola();
	//  QScriptValue makeparabola;
	//  QScriptValue makeoffsetcurve();
	

	//  //mesh
	//  QScriptValue makemesh();
	//  QScriptValue makecoloredmesh();

	// surfaces
		QScriptValue makeloft();
		

	//  // vectors	
		QScriptValue makevector();
	//  QScriptValue makevectortangenttocurve()
	// 
	//  // operations
	//  QScriptValue movepointtopoint();
	//  QScriptValue rotate();
	//  QScriptValue mirror();
	//  QScriptValue movebyvector();
	//  QScriptValue axistoaxis();

	//  QScriptValue intersect();
	//  QScriptValue split();
	//  QScriptValue booleancut();
	//  QScriptValue booleancommon();
	//  QScriptValue booleanglue();

	//  // get info
	//  QScriptValue getlength();
	//  QScriptValue getarea();
	//  QScriptValue getmindistance();
	//  QScriptValue getmaxdistance();
	//  QScriptValue getuvpointonsurface();
	//  QScriptValue getbiggestface();
	//  QScriptValue getbiggestshell();
	//  QScriptValue getbiggestsolid();

	//  // filesystem operations
	//  QScriptValue loadtextfile();
	//  QScriptValue loadbinaryfile();
	//  QScriptValue importigs();
	//  QScriptValue importstp();
	//  QScriptValue importstl();
	//  QScriptValue exportigs();
	//  QScriptValue exportstp();

 };

#endif