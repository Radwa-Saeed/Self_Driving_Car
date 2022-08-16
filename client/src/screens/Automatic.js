import { StyleSheet, View ,Text} from "react-native";
import { useNavigation } from "@react-navigation/native";
import React from "react";


export default function Automatic() {

  return (
    <View style={styles.container}>
        <Text> Your App is running in Automatic Mode </Text>
     
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  }
});
