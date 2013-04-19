// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaOperation.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocument.h"
            
                #include "RExporter.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaRequireHeap.h"
                
                  #include "REcmaNonCopyable.h"
                 void REcmaOperation::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (ROperation*) 0)));
        protoCreated = true;
    }

    
        // primary base class RRequireHeap:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RRequireHeap*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class RRequireHeap
        REcmaHelper::registerFunction(&engine, proto, getRRequireHeap, "getRRequireHeap");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, apply, "apply");
            
            REcmaHelper::registerFunction(&engine, proto, getEntityTypeFilter, "getEntityTypeFilter");
            
            REcmaHelper::registerFunction(&engine, proto, setRecordAffectedObjects, "setRecordAffectedObjects");
            
            REcmaHelper::registerFunction(&engine, proto, setSpatialIndexDisabled, "setSpatialIndexDisabled");
            
        engine.setDefaultPrototype(
            qMetaTypeId<ROperation*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("ROperation",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaOperation::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class ROperation: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaOperation::getRRequireHeap(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RRequireHeap* cppResult =
                    qscriptvalue_cast<ROperation*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaOperation::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("ROperation"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaOperation::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RRequireHeap");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaOperation::apply
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOperation::apply", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOperation::apply";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROperation* self = 
                        getSelf("apply", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocument */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("ROperation: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'RTransaction'
    RTransaction cppResult =
        
               self->apply(a0);
        // return type: RTransaction
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocument */
     && (
            context->argument(1).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("ROperation: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
                    // argument isStandardType
                    bool
                    a1 =
                    (bool)
                    
                    context->argument( 1 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'RTransaction'
    RTransaction cppResult =
        
               self->apply(a0
        ,
    a1);
        // return type: RTransaction
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROperation.apply().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOperation::apply", context, engine);
            return result;
        }
         QScriptValue
        REcmaOperation::getEntityTypeFilter
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOperation::getEntityTypeFilter", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOperation::getEntityTypeFilter";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROperation* self = 
                        getSelf("getEntityTypeFilter", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RS::EntityType'
    RS::EntityType cppResult =
        
               self->getEntityTypeFilter();
        // return type: RS::EntityType
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROperation.getEntityTypeFilter().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOperation::getEntityTypeFilter", context, engine);
            return result;
        }
         QScriptValue
        REcmaOperation::setRecordAffectedObjects
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOperation::setRecordAffectedObjects", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOperation::setRecordAffectedObjects";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROperation* self = 
                        getSelf("setRecordAffectedObjects", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    bool
                    a0 =
                    (bool)
                    
                    context->argument( 0 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setRecordAffectedObjects(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROperation.setRecordAffectedObjects().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOperation::setRecordAffectedObjects", context, engine);
            return result;
        }
         QScriptValue
        REcmaOperation::setSpatialIndexDisabled
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOperation::setSpatialIndexDisabled", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOperation::setSpatialIndexDisabled";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROperation* self = 
                        getSelf("setSpatialIndexDisabled", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    bool
                    a0 =
                    (bool)
                    
                    context->argument( 0 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setSpatialIndexDisabled(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROperation.setSpatialIndexDisabled().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOperation::setSpatialIndexDisabled", context, engine);
            return result;
        }
         QScriptValue REcmaOperation::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    ROperation* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("ROperation(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaOperation::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        ROperation* self = getSelf("ROperation", context);
        //Q_ASSERT(self!=NULL);
        if (self==NULL) {
            return REcmaHelper::throwError("self is NULL", context);
        }
        
    
        delete self;
        context->thisObject().setData(engine->nullValue());
        context->thisObject().prototype().setData(engine->nullValue());
        context->thisObject().setPrototype(engine->nullValue());
        context->thisObject().setScriptClass(NULL);
        return engine->undefinedValue();
    }
    ROperation* REcmaOperation::getSelf(const QString& fName, QScriptContext* context)
    
        {
            ROperation* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<ROperation >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("ROperation.%1(): "
                        "This object is not a ROperation").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        ROperation* REcmaOperation::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          ROperation* selfBase = getSelf(fName, context);
                ROperation* self = dynamic_cast<ROperation*>(selfBase);
                //return REcmaHelper::scriptValueTo<ROperation >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("ROperation.%1(): "
                    "This object is not a ROperation").arg(fName),
                    context);
            }

            return self;
            


        }
        