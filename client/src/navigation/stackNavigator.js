import React from "react";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

import Manual from "../screens/Manual";
import Home from "../screens/Home";
import Automatic from "../screens/Automatic";

const Stack = createNativeStackNavigator();

const StackNavigator = () => {
  return (
    <Stack.Navigator>
      <Stack.Group>
        <Stack.Screen name="Home" component={Home} />
        <Stack.Screen name="Automatic" component={Automatic}/>
        <Stack.Screen name="Manual" component={Manual}/>
      </Stack.Group>
    </Stack.Navigator>
  );
};

export default StackNavigator;
