class vec {
    public:
        float x, y;

        /* constructors */
        vec(float xin = 0.0f, float yin = 0.0f){ 
            x = xin;
            y = yin;
        }

        /* overloads */
        vec operator+(vec const& rhs){ return vec(x + rhs.x, y + rhs.y); }

    	vec& operator+=(vec const& rhs){
	    	x += rhs.x;
		    y += rhs.y;

		    return *this;
    	}

	    vec operator*(float rhs){ return vec(x * rhs, y * rhs); }
}

const int ballDimension = 20;

class ball {
    public:
        vec position;
        SDL_Rect rectBall{};

        ball(vec pos){ 
            position = pos; 
            rectBall.x = static_cast<int>(position.x);
            rectBall.y = static_cast<int>(position.y);
            rectBall.w = ballDimension;
            rectBall.h = ballDimension;
        }

        
}

class paddle {

}