//
// Copyright (c) 2016 - 2017 Mesh Consultants Inc.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


#include "Input_SliderListener.h"

#include <vector>
#include <Urho3D/Core/Variant.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Slider.h>
#include "Widget_OptionSlider.h"

#include "IoGraph.h"

using namespace Urho3D;

String Input_SliderListener::iconTexture = "Textures/Icons/Input_SliderListener.png";

Input_SliderListener::Input_SliderListener(Urho3D::Context* context) : IoComponentBase(context, 1, 1)
{
	SetName("SliderListener");
	SetFullName("Slider Listener");
	SetDescription("Listens for slider input");
	SetGroup(IoComponentGroup::SCENE);
	SetSubgroup("INPUT");


	inputSlots_[0]->SetName("Sliders");
	inputSlots_[0]->SetVariableName("SP");
	inputSlots_[0]->SetDescription("Pointers to sliders");
	inputSlots_[0]->SetVariantType(VariantType::VAR_VOIDPTR);
	inputSlots_[0]->SetDataAccess(DataAccess::ITEM);

	//inputSlots_[1]->SetName("Range");
	//inputSlots_[1]->SetVariableName("R");
	//inputSlots_[1]->SetDescription("Range of slider");
	//inputSlots_[1]->SetVariantType(VariantType::VAR_VECTOR3);
	//inputSlots_[1]->SetDataAccess(DataAccess::ITEM);
	//inputSlots_[1]->SetDefaultValue(Vector3(0, 50, 0));
	//inputSlots_[1]->DefaultSet();

	outputSlots_[0]->SetName("Slider Values");
	outputSlots_[0]->SetVariableName("SV");
	outputSlots_[0]->SetDescription("Values of Sliders out");
	outputSlots_[0]->SetVariantType(VariantType::VAR_FLOAT); // this would change to VAR_FLOAT if access becomes LIST
	outputSlots_[0]->SetDataAccess(DataAccess::ITEM);



}

void Input_SliderListener::PreLocalSolve()
{

}


void Input_SliderListener::SolveInstance(
	const Vector<Variant>& inSolveInstance,
	Vector<Variant>& outSolveInstance
	)
{
	if (inSolveInstance[0].GetPtr() == NULL)
	{
		SetAllOutputsNull(outSolveInstance);
		return;
	}
	
	float val = 0.0f;
    float min = 0.0f;
//	Slider* slider = (Slider*)inSolveInstance[0].GetVoidPtr();
    
    Widget_OptionSlider* optionSlider = (Widget_OptionSlider*)inSolveInstance[0].GetPtr();
    
    String typeName = optionSlider->GetTypeName();
 //   if (optionSlider && typeName == Slider::GetTypeNameStatic())
    if (optionSlider && typeName == Widget_OptionSlider::GetTypeNameStatic())
    {
        Slider* slider = (Slider*)optionSlider->GetChild("MainSlider", false);
        SubscribeToEvent(slider, E_SLIDERCHANGED, URHO3D_HANDLER(Input_SliderListener, HandleSliderChanged));
        

        min = optionSlider->GetMin();
        
        val = min + slider->GetValue();
        
    }
    
//	String typeName = slider->GetTypeName();
//	if (slider && typeName == Slider::GetTypeNameStatic())
//	{
//		SubscribeToEvent(slider, E_SLIDERCHANGED, URHO3D_HANDLER(Input_SliderListener, HandleSliderChanged));
//
//		val = slider->GetValue();
//	}


	outSolveInstance[0] = val;
}

void Input_SliderListener::HandleSliderChanged(StringHash eventType, VariantMap& data)
{
	solvedFlag_ = 0;
	GetSubsystem<IoGraph>()->QuickTopoSolveGraph();
}
