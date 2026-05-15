#pragma once

namespace MathLibrary
{
    struct Color
    {
        unsigned int rgba;

        Color()
        {
            rgba = 255;
        }

        Color(Color & Given_Color)
        {
            rgba = Given_Color.rgba;
        }
        
        Color(unsigned char Given_R, unsigned char Given_G, unsigned char Given_B, unsigned char Given_A)
        {
            rgba = Given_R << 24 | Given_G << 16 | Given_B << 8 | Given_A;
        }

        unsigned char GetRed() const
        {
            return (unsigned char)(rgba >> 24);
        }

        unsigned char GetGreen() const
        {
            return (unsigned char)(rgba >> 16);
        }

        unsigned char GetBlue() const
        {
            return (unsigned char)(rgba >> 8);
        }

        unsigned char GetAlpha() const
        {
            return (unsigned char)(rgba);
        }

        void SetRed(unsigned char Rhs_Red_Value) 
        {
            rgba &= 0x00ffffff;
            rgba |= Rhs_Red_Value << 24;
        }

        void SetGreen(unsigned char Rhs_Green_Value)
        {
            rgba &= 0xff00ffff;
            rgba |= Rhs_Green_Value << 16;
        }

        void SetBlue(unsigned char Rhs_Blue_Value)
        {
           rgba &= 0xffff00ff;
           rgba |= Rhs_Blue_Value << 8;
        }

        void SetAlpha(unsigned char Rhs_Alpha_Value)
        {
            rgba &= 0xffffff00;
            rgba |= Rhs_Alpha_Value;
        }

        bool operator==(const Color Rhs_Color) const
        {
            return(rgba == Rhs_Color.rgba);
        }

        void shift_by_16() 
        {
            rgba = rgba >> 16;
        }
    };
}