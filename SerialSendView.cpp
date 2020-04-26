#include "SerialSendView.hpp"

SerialSendView::SerialSendView(){


        //TODO make this a function?
        //Set Visuals
        this->border.segments.disable_all();
        this->border.segments.north.enable();
        this->border.enable();

        this->height_policy.maximum(4);

        this->make_child<SerialTextInputView>();
        this->make_child<SerialSendButtonView>();
        this->make_child<SerialChoiceButtonView>();
        }
