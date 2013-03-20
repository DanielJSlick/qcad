

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is copyable.
        
        #ifndef RECMACIRCLE_H
        #define RECMACIRCLE_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RCircle.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaCircle {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getRShape(QScriptContext *context,
            QScriptEngine *engine)
        ;

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    static  QScriptValue getSetCenter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue getSetRadius
        (QScriptContext* context, QScriptEngine* engine) 
        ;

    // public methods:
    static  QScriptValue
        clone
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        createFrom3Points
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        to2D
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getBoundingBox
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getLength
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getEndPoints
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getMiddlePoints
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getCenterPoints
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getPointsWithDistanceToEnd
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getVectorTo
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getCenter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setCenter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getRadius
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setRadius
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getDiameter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setDiameter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getCircumference
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setCircumference
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getArea
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setArea
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        move
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        rotate
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        scale
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mirror
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        flipHorizontal
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        flipVertical
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue copy
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RCircle* getSelf(const QString& fName, QScriptContext* context)
    ;static RCircle* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    