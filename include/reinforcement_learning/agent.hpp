#pragma once

namespace Wander{ 

    class Reward {};

    // agent type should depend on how agent live in the world 
    class Agent{

        public:
            virtual Reward GetReWard() { return Reward{};}; 
            virtual void TakeAction() {}; 

    };

    // Todo: Reward type should depend on AgentType 
    class OnlyVisionAngent :public Agent {
    };


    class OnlyTouching:public Agent {
    };

    class OnlySmelling:public Agent {
    };

    class OnlyActing:public Agent {
    };


    class HumanAgent: public OnlyActing,OnlySmelling,OnlyTouching,OnlyVisionAngent {
    };


    

}
