/*Copyright (c) 2019 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "gtest/gtest.h"
#include "../EU4toV2/Source/EU4World/Modifiers/Modifier.h"
#include <sstream>



TEST(EU4World_ModifierTests, effectDefaultToEmpty)
{
	std::stringstream input;
	EU4::Modifier theModifier(input);

	ASSERT_EQ(theModifier.getAllEffects().size(), 0);
}


TEST(EU4World_ModifierTests, nonExistentEffectHasAmountOfZero)
{
	std::stringstream input;

	EU4::Modifier theModifier(input);
	ASSERT_EQ(theModifier.getEffectAmount("non_existent_modifier"), 0);
}


TEST(EU4World_ModifierTests, effectcanBeAdded)
{
	std::stringstream input;
	input << "= {\n";
	input << "\teffect = 0.5\n";
	input << "}";

	EU4::Modifier theModifier(input);

	ASSERT_EQ(theModifier.getAllEffects().size(), 1);
	ASSERT_EQ(theModifier.getAllEffects().at("effect"), 0.5);
}


TEST(EU4World_ModifierTests, effectAmountsAreReturned)
{
	std::stringstream input;
	input << "= {\n";
	input << "\teffect = 0.5\n";
	input << "}";

	EU4::Modifier theModifier(input);
	ASSERT_EQ(theModifier.getEffectAmount("effect"), 0.5);
}