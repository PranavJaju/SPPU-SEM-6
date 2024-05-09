    using System.Collections;
    using System.Collections.Generic;
    using UnityEngine;
    using UnityEngine.UI;    // Add this step
    public class ApplyColor : MonoBehaviour
    {
        public FlexibleColorPicker fcp;
        public Material m;
        public Material s;
        public Material p;
        public Button cubeButton;
        public Button SphereButton;
        public Button PlaneButton;
        public Texture txt1;
        public Texture txt2;
        private bool toggle = false;
        // Start is called before the first frame update
        void Start()
        {
            cubeButton.onClick.AddListener(()=>changeColorNMaterial(m));
            SphereButton.onClick.AddListener(()=>changeColorNMaterial(s));
            PlaneButton.onClick.AddListener(()=>changeColorNMaterial(p));
        }

        void changeColorNMaterial(Material m1){
            m1.color = fcp.color;
        }

        void Update(){
            if(Input.GetKeyDown(KeyCode.C)){
                if(!toggle){
                    m.mainTexture = txt1;
                    toggle = true;
                }
                else{
                    m.mainTexture = txt2;
                    toggle = false;
                }
            }
        }
    }
