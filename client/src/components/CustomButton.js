import Icon from 'react-native-vector-icons/AntDesign';
import { StyleSheet, Text, View } from "react-native";
import React from "react";

const AppButton = ({ onPress, icon, title }) => (
  <View>
    <Icon.Button
      name={icon}
      onPress={onPress}
      style={styles.appButton}
    >
      <Text style={styles.appButtonText}>{title}</Text>
    </Icon.Button>
  </View>
);

const styles = StyleSheet.create({
    appButton: {
      alignItems: "center",
      justifyContent: "center",
      paddingVertical: 12,
      paddingHorizontal: 32,
      elevation: 3,
    },
    appButtonText: {
      fontSize: 16,
      lineHeight: 21,
      fontWeight: "bold",
      letterSpacing: 0.25,
      color: "white",
    },
  });

export default AppButton;