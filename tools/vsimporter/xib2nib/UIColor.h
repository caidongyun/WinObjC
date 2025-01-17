//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once
#include "ObjectConverter.h"

typedef enum colorSpace
{
    colorSpaceFull,
    colorSpaceWhite,
    colorSpaceRGB,
    colorSpaceName
};
class UIColor :
    public ObjectConverter
{
public:
    UIColor();
    UIColor(char *systemName);
    UIColor(int colorSpace, int componentCount, float r, float g, float b, float a, char *systemName);
    colorSpace _colorSpaceOut;
    int _colorSpace, _componentCount;
    float _r, _g, _b, _a;
    float _white;
    const char *_systemName;

    virtual void InitFromXIB(XIBObject *obj);
    virtual void InitFromStory(XIBObject *obj);
    virtual void ConvertStaticMappings(NIBWriter *writer, XIBObject *obj);
    ObjectConverter *Clone();
    XIBObject *CreateObject(NIBWriter *writer);
};

