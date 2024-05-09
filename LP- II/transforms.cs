using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class transforms : MonoBehaviour
{
    public Transform target_object; 
    private float rotational_speed = 1500f;
    private float translate_speed = 2f;
    private float scale_speed = 0.1f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.R)){
            rotateObject();
        }   
        if(Input.GetKeyDown(KeyCode.M)){
            scaleObject(1);
        }
        if(Input.GetKeyDown(KeyCode.N)){
            scaleObject(-1);
        }

        translateObject();
    }
    void scaleObject(int s){
        target_object.localScale += new Vector3(scale_speed,scale_speed,scale_speed) * s;
    }
    void rotateObject(){
        float r = rotational_speed * Time.deltaTime;
        transform.Rotate(Vector3.up,r);
    }
    void translateObject(){
         float x  = Input.GetAxis("Horizontal")*translate_speed*Time.deltaTime;
         float y  = Input.GetAxis("Vertical")*translate_speed*Time.deltaTime;
         target_object.Translate(new Vector3(x,y,0));
    }
}
