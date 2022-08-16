import { StyleSheet, View , Text} from "react-native";
import { useNavigation } from "@react-navigation/native";
import AppButton from "../components/CustomButton";
import React from "react";
export default function Home() {


  
  const clickHandler = (id) => {
    console.log(id)
    const PostURL =`http:// 192.168.146.174:8000/get/?val=${id}`
    fetch(PostURL)
    
    .catch((error) => alert(error)) // 
  };
  const navigation = useNavigation();
  const navigationHandler = (id) => {
      if (id === 0) {
        navigation.navigate("Manual");
      } else {
        navigation.navigate("Automatic");
          
      }
    
  };
  return (
    <View style={styles.container}>
        <AppButton  title="Manual" onPress={() => { clickHandler(0) ;navigationHandler(0);} }/>
        <View style={styles.m1}/>
        <AppButton  title="Automatic"  onPress={() => {  clickHandler(1) ; navigationHandler(1);}}/>
    </View>

  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  m1:{
    marginTop:20
  }
});
