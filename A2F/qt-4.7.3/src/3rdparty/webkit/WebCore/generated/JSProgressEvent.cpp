/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSProgressEvent.h"

#include "ProgressEvent.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSProgressEvent);

/* Hash table */

static const HashTableValue JSProgressEventTableValues[5] =
{
    { "lengthComputable", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventLengthComputable), (intptr_t)0 },
    { "loaded", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventLoaded), (intptr_t)0 },
    { "total", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventTotal), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSProgressEventTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSProgressEventTableValues, 0 };
#else
    { 9, 7, JSProgressEventTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSProgressEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSProgressEventConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSProgressEventConstructorTableValues, 0 };
#else
    { 1, 0, JSProgressEventConstructorTableValues, 0 };
#endif

class JSProgressEventConstructor : public DOMConstructorObject {
public:
    JSProgressEventConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSProgressEventConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSProgressEventPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSProgressEventConstructor::s_info = { "ProgressEventConstructor", 0, &JSProgressEventConstructorTable, 0 };

bool JSProgressEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSProgressEventConstructor, DOMObject>(exec, &JSProgressEventConstructorTable, this, propertyName, slot);
}

bool JSProgressEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSProgressEventConstructor, DOMObject>(exec, &JSProgressEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSProgressEventPrototypeTableValues[2] =
{
    { "initProgressEvent", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsProgressEventPrototypeFunctionInitProgressEvent), (intptr_t)6 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSProgressEventPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSProgressEventPrototypeTableValues, 0 };
#else
    { 2, 1, JSProgressEventPrototypeTableValues, 0 };
#endif

const ClassInfo JSProgressEventPrototype::s_info = { "ProgressEventPrototype", 0, &JSProgressEventPrototypeTable, 0 };

JSObject* JSProgressEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSProgressEvent>(exec, globalObject);
}

bool JSProgressEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSProgressEventPrototypeTable, this, propertyName, slot);
}

bool JSProgressEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSProgressEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSProgressEvent::s_info = { "ProgressEvent", &JSEvent::s_info, &JSProgressEventTable, 0 };

JSProgressEvent::JSProgressEvent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<ProgressEvent> impl)
    : JSEvent(structure, globalObject, impl)
{
}

JSObject* JSProgressEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSProgressEventPrototype(JSProgressEventPrototype::createStructure(JSEventPrototype::self(exec, globalObject)));
}

bool JSProgressEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSProgressEvent, Base>(exec, &JSProgressEventTable, this, propertyName, slot);
}

bool JSProgressEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSProgressEvent, Base>(exec, &JSProgressEventTable, this, propertyName, descriptor);
}

JSValue jsProgressEventLengthComputable(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->lengthComputable());
    return result;
}

JSValue jsProgressEventLoaded(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->loaded());
    return result;
}

JSValue jsProgressEventTotal(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->total());
    return result;
}

JSValue jsProgressEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* domObject = static_cast<JSProgressEvent*>(asObject(slotBase));
    return JSProgressEvent::getConstructor(exec, domObject->globalObject());
}
JSValue JSProgressEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSProgressEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsProgressEventPrototypeFunctionInitProgressEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSProgressEvent::s_info))
        return throwError(exec, TypeError);
    JSProgressEvent* castedThisObj = static_cast<JSProgressEvent*>(asObject(thisValue));
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThisObj->impl());
    const UString& typeArg = args.at(0).toString(exec);
    bool canBubbleArg = args.at(1).toBoolean(exec);
    bool cancelableArg = args.at(2).toBoolean(exec);
    bool lengthComputableArg = args.at(3).toBoolean(exec);
    unsigned loadedArg = args.at(4).toInt32(exec);
    unsigned totalArg = args.at(5).toInt32(exec);

    imp->initProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg);
    return jsUndefined();
}


}
