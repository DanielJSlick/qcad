


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #ifndef RECMASHELLTREEWIDGET_H
        #define RECMASHELLTREEWIDGET_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RTreeWidget.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaShellTreeWidget : public RTreeWidget {

        public:
      
    // Destructor:
    
            ~REcmaShellTreeWidget();
        static RTreeWidget* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellTreeWidget* getSelfShell(const QString& fName, QScriptContext* context)
    ;
    
    
    // Constructors:
    
      REcmaShellTreeWidget(
                QWidget * parent
        = 0
            );
        
    
    
      void contextMenuEvent(
                QContextMenuEvent * e
            );
        
    
    
      void mousePressEvent(
                QMouseEvent * e
            );
        
    
    
      void mouseReleaseEvent(
                QMouseEvent * e
            );
        
    
    
      void mouseMoveEvent(
                QMouseEvent * e
            );
        
    
  

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	static  QScriptValue
        contextMenuEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mousePressEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mouseReleaseEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mouseMoveEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;QScriptValue __qtscript_self;
            };
            Q_DECLARE_METATYPE(REcmaShellTreeWidget*)
        
	#endif
    